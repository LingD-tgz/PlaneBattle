#pragma once
#include "TEntity.h"
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

#define DATA_USERID	Qt::UserRole+1

/* �����е�item
   ÿ��item����һ����ʱ��������������ײ���
*/
class CTSceneItem : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	CTSceneItem(CTEntityPtr pEntity); // ÿ��item��һ��ʵ���
	~CTSceneItem();

private slots:
	/* ��ײ���timer��Ӧ���� */
	void onHitChectTimer();

private:
	QTimer m_hitCheckTimer; // ��ײ���timer
};

typedef std::shared_ptr<CTSceneItem> CTSceneItemPtr;


