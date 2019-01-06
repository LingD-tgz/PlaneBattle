#include "PlaneBattle.h"
#include "TGlobal.h"
#include "TScene.h"
#include <QPoint>

TankBattle::TankBattle(QWidget *parent)
	: QMainWindow(parent)
	, m_pView(nullptr)
{
	ui.setupUi(this);
}

TankBattle::~TankBattle()
{

}

void TankBattle::initWidget()
{
	CTScenePtr pScene = CTGlobal::instance()->getScene();
	if (pScene == nullptr)
	{
		return;
	}
	// ��ʼ������
	m_pView = new QGraphicsView();
	m_pView->setScene(pScene.get()); // ���������õ�QGraphicsView��
	m_pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // ���ش�ֱ������
	m_pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // ����ˮƽ������
	setCentralWidget(m_pView); // ����QGraphicsViewΪ���Ĵ���

	// ���ݴ��ڴ�С���ó����߽�
	QRect rt = rect(), sceneRange;
	sceneRange.setWidth(rt.width());
	sceneRange.setHeight(rt.height());
	pScene->setSceneRange(sceneRange);
	
	// ��������ʼ��
	CTGlobal::instance()->getControler()->init();
}

void TankBattle::resizeEvent(QResizeEvent* event)
{
	CTScenePtr pScene = CTGlobal::instance()->getScene();
	if (pScene == nullptr)
	{
		return;
	}

	QSize rt = event->size();
	QRect sceneRange(0,0,0,0);
	sceneRange.setWidth(rt.width());
	sceneRange.setHeight(rt.height());
	pScene->setSceneRange(sceneRange);
}
