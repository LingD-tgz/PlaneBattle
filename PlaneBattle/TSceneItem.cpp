
#include "TSceneItem.h"
Q_DECLARE_METATYPE(GUID)

CTSceneItem::CTSceneItem(CTEntityPtr pEntity)
{
	setData(DATA_USERID, QVariant::fromValue<GUID>(pEntity->getID())); // ��item���û���������Ϊʵ��ID
	
	// ����itemͼ��
	QPixmap pix = QPixmap("plane_icon.png");
	// ����ͼ���������ʵ���С����ȹ̶���ֻ�����߶ȣ�
	int entityWidth = pEntity->getSize().width(); // ʵ����
	QSize size;
	size.setWidth(entityWidth);
	size.setHeight(pix.height()/(float)pix.width()*entityWidth);
	pEntity->setSize(size);
	pix.scaled(pEntity->getSize(), Qt::KeepAspectRatio); // ͼ�����ʵ���С��������
	setPixmap(pix); // ����ͼ��

	connect(&m_hitCheckTimer, SIGNAL(timeout()), this, SLOT(onHitChectTimer()));
	m_hitCheckTimer.start(17); // ÿһ֡��17ms��������һ����ײ���
}

CTSceneItem::~CTSceneItem()
{
	m_hitCheckTimer.stop();
}

void CTSceneItem::onHitChectTimer()
{
	QList<QGraphicsItem*> items = collidingItems(); // ��ȡ�͵�ǰitem��ײ��item�б�
	if (items.size() <= 0)
	{
		return;
	}

	// ����к��Լ���ײ��item����ǰitem�ı�״̬
	// ��ǰitem���������Ա���ʵ������ֵ��Ϊ0��
	// ��ǰitem�Ƿɻ��������ײ��������������������˺��ȼ���ʵ������ֵ�������ײ���Ƿɻ������Ա���ʵ������ֵ��Ϊ0��
	
	// �޸�ʵ�����Ե��߼�Ӧ�÷ŵ�ʲôλ�ô������ŵ��˴������Ƿ�Υ��MVC���ԭ��������ڴ˴�����������ÿ���������
}
