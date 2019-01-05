#include "TScene.h"
#include "TGlobal.h"

Q_DECLARE_METATYPE(GUID)

CTScene::CTScene(void)
	: m_pControlerEntity(nullptr)
{
}

CTScene::~CTScene(void)
{
}

void CTScene::setSceneRange(QRectF rect)
{
	m_rect = rect;
}

QPointF CTScene::coordinateEntityToScene(QPointF pos)
{
	// ���Ƕ���ʵ������ϵ�Գ���������±߽��м�λ��Ϊԭ��(0,0)���췽ʵ��ĳ�ʼλ��
	// ʵ���ϳ���������ԭ��(0,0)�ڳ��������Ͻ�λ��
	// �������������ϵͬʱ����һ������ʱ����Ҫ��������ת��
	// ת����ʽ��entityPos+QPointF(rect.width/2.0, rect.height)
	return pos + QPointF(m_rect.width()/2.0 ,m_rect.height());
}

void CTScene::addItemToScene(CTEntityPtr entity)
{
	// ����ʵ�崴����Ӧ��item
	CTSceneItem* pItem = new CTSceneItem(entity);
	pItem->setPos(coordinateEntityToScene(entity->getPos())); // ��ʵ���λ�ý�������ת��������Ϊitem��λ��
	
	// ��item���뵽������
	addItem(pItem);
}

void CTScene::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Left)
	{
		m_bLeftMove = true;
		m_bRightMove = false;// ���Ҳ���ͬ��
	}
	else if (event->key() == Qt::Key_Right)
	{
		m_bLeftMove = false;// ���Ҳ���ͬ��
		m_bRightMove = true;
	}
	else if (event->key() == Qt::Key_Up)
	{
		m_bUpMove = true;
		m_bDownMove = false;// ���²���ͬ��
	}
	else if (event->key() == Qt::Key_Down)
	{
		m_bUpMove = false;// ���²���ͬ��
		m_bDownMove = true;
	}
}

void CTScene::keyReleaseEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Left)
	{
		m_bLeftMove = false;
	}
	else if (event->key() == Qt::Key_Right)
	{
		m_bRightMove = false;
	}
	else if (event->key() == Qt::Key_Up)
	{
		m_bUpMove = false;
	}
	else if (event->key() == Qt::Key_Down)
	{
		m_bDownMove = false;
	}
}

CTSceneItem* CTScene::getControler()
{
	CTSceneItem* redEntity = nullptr;
	QList<QGraphicsItem *> itemList = items();
	for each(auto item in itemList)
	{
		GUID id = item->data(DATA_USERID).value<GUID>();
		CTEntityPtr pEntity = CTGlobal::instance()->getModelManager()->getEntityByID(id);
		if (pEntity)
		{
			CTEntity::Camp camp = pEntity->getCamp();
			if (camp == CTEntity::Red)
			{
				redEntity = (CTSceneItem*)item;
				break;
			}
		}
	}
	return redEntity;
}

void CTScene::onControlerTimer()
{
	// �����߶�ʱ����ֻ�����û������޸�ʵ������
	if (m_pControlerEntity == nullptr)
	{
		CTEntityList entityList = CTGlobal::instance()->getModelManager()->getEntityList();
		auto res = std::find_if(entityList.begin(), entityList.end(), [](CTEntityPtr pEntity){return pEntity->getCamp() == CTEntity::Red;});
		if (res == entityList.end())
		{
			return;
		}
		m_pControlerEntity = *res;
	}
	// ��ȡʵ�嵱ǰλ��
	QPointF pt = m_pControlerEntity->getPos();
	// λ�ñ仯��
	QPoint dpt;
	if (m_bLeftMove && pt.x()>0)
	{
		dpt.setX(-5);
	}
	
	QSize itemSize= m_pControlerEntity->getSize();
	QRectF screenRect = sceneRect();
	if (m_bRightMove && pt.x()<screenRect.width()-itemSize.width())
	{
		dpt.setX(5);
	}
	if (m_bUpMove && pt.y()>0)
	{
		dpt.setY(-5);
	}
	if (m_bDownMove && pt.y()<screenRect.height()-itemSize.height())
	{
		dpt.setY(5);
	}
	pt = pt + dpt;
	m_pControlerEntity->setPos(pt);
}

void CTScene::onRefreshTimer()
{
	// ˢ�¶�ʱ����������ʵ������ˢ��������Ӧ��item
}
