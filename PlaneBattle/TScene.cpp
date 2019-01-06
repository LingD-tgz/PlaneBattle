#include "TScene.h"
#include "TGlobal.h"

Q_DECLARE_METATYPE(GUID)

CTScene::CTScene(void)
	: m_pControlerEntity(nullptr)
	, m_bLeftMove(false)
	, m_bRightMove(false)
	, m_bUpMove(false)
	, m_bDownMove(false)
{
	bool bConnect = connect(&m_controlerTimer, SIGNAL(timeout()), this, SLOT(onControlerTimer()));
	bool bConnect1 = connect(&m_refreshTimer, SIGNAL(timeout()), this, SLOT(onRefreshTimer()));
	m_controlerTimer.start(30);
	m_refreshTimer.start(17); // ����ÿ��60֡�����ʽ���ˢ�£���Լ17msһ��ˢ��
}

CTScene::~CTScene(void)
{
}

void CTScene::setSceneRange(QRectF rect)
{
	m_rect = rect;
	setSceneRect(m_rect); // ���ó����߽�
}

QPointF CTScene::coordinateEntityToScene(QPointF pos)
{
	// ���Ƕ���ʵ������ϵ�Գ���������±߽��м�λ��Ϊԭ��(0,0)���췽ʵ��ĳ�ʼλ��
	// ʵ���ϳ���������ԭ��(0,0)�ڳ��������Ͻ�λ��
	// �������������ϵͬʱ����һ������ʱ����Ҫ��������ת��
	// ת����ʽ��entityPos+QPointF(rect.width/2.0, rect.height)
	return pos + QPointF(m_rect.width()/2.0 ,m_rect.height());
}

QPointF CTScene::coordinateSceneToEntity(QPointF pos)
{
	return pos - QPointF(m_rect.width()/2.0 ,m_rect.height());
}

void CTScene::addItemToScene(CTEntityPtr entity)
{
	// ����ʵ�崴����Ӧ��item
	CTSceneItem* pItem = new CTSceneItem(entity);

	// ��ʵ���λ�ý�������ת��������Ϊitem��λ��
	QPointF pos = coordinateEntityToScene(entity->getPos());
	QRectF itemRect = pItem->boundingRect();
	pItem->setPos(pos.rx()-itemRect.width()/2.0, pos.ry()-itemRect.height());  // ����ʵ��ĵ׶�����Ϊʵ�������
	
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

	QSize itemSize= m_pControlerEntity->getSize(); // ʵ��item�Ĵ�С
	QRectF screenRect = sceneRect(); // �����߽�

	// ��ȡʵ���ڳ����е�λ��(֮����Ҫת���������е�λ�ã���Ϊ���ж�ʵ���Ƿ����������߽�)
	QPointF pt = coordinateEntityToScene(m_pControlerEntity->getPos());
	pt = QPointF(pt.rx()-itemSize.width()/2.0, pt.ry()-itemSize.height()); // ����ʵ��ĵ׶�����Ϊʵ�������
	// λ�ñ仯��
	QPoint dpt;
	if (m_bLeftMove && pt.x()>0)
	{
		dpt.setX(-5);
	}
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
	pt = QPointF(pt.rx()+itemSize.width()/2.0, pt.ry()+itemSize.height());
	// ��ʵ���ڳ����е�����ת��Ϊʵ������
	pt = coordinateSceneToEntity(pt);
	m_pControlerEntity->setPos(pt);
}

void CTScene::onRefreshTimer()
{
	// ˢ�¶�ʱ����������ʵ������ˢ��������Ӧ��item
	QList<QGraphicsItem *> itemList = items();
	for each(auto item in itemList)
	{
		GUID id = item->data(DATA_USERID).value<GUID>();
		CTEntityPtr pEntity = CTGlobal::instance()->getModelManager()->getEntityByID(id);
		if (pEntity == nullptr)
		{
			continue;
		}
		// ��ʵ������ת��Ϊ��������
		QPointF pos = coordinateEntityToScene(pEntity->getPos());
		QRectF itemRect = item->boundingRect();
		item->setPos(pos.rx()-itemRect.width()/2.0, pos.ry()-itemRect.height()); // ����ʵ��ĵ׶�����Ϊʵ�������
	}
}
