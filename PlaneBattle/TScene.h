#pragma once
#include "TEntity.h"
#include "TSceneItem.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QRectF>
#include <QTimer>

/* ������ */
class CTScene : public QGraphicsScene
{
	Q_OBJECT

public:
	CTScene(void);
	~CTScene(void);

	/* ���ó����߽� */
	void setSceneRange(QRectF rect);

	/* ʵ�����굽���������ת�� */
	QPointF coordinateEntityToScene(QPointF pos);

	/* �������굽ʵ�������ת�� */
	QPointF coordinateSceneToEntity(QPointF pos);

	/* ����item��������ʵ��� */
	void addItemToScene(CTEntityPtr entity);

	/* �����û��¼� */
	void keyPressEvent(QKeyEvent* event);
	
	/* �����ͷ��¼� */
	void keyReleaseEvent(QKeyEvent* event);

	/* ��ȡ�����ߣ��췽ʵ�壬ֻ��һ���� */
	CTSceneItem* getControler();

private slots:
	/* �����߶�ʱ����Ӧ���� */
	void onControlerTimer();

	/* ˢ�¶�ʱ����Ӧ���� */ 
	void onRefreshTimer();

private:
	QRectF m_rect; // �����߽�
	
	QTimer m_controlerTimer; // �����߶�ʱ��
	QTimer m_refreshTimer; // ˢ�¶�ʱ��

	bool m_bLeftMove; // ���Ʊ�־λ
	bool m_bRightMove; // ���Ʊ�־λ
	bool m_bUpMove; // ���Ʊ�־λ
	bool m_bDownMove; // ���Ʊ�־λ

	CTEntityPtr m_pControlerEntity; // ������ʵ��
};

typedef std::shared_ptr<CTScene> CTScenePtr;

