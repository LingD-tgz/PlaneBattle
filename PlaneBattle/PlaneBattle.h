#ifndef TANKBATTLE_H
#define TANKBATTLE_H

#include "ui_PlaneBattle.h"
#include <QtWidgets/QMainWindow>
#include <QGraphicsView>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QTimer>

class TankBattle : public QMainWindow
{
	Q_OBJECT

public:
	TankBattle(QWidget *parent = 0);
	~TankBattle();

	/* ��ʼ�����ڴ�С */
	void initWidget();

	/* ���ڴ�С�ı��¼���Ӧ���� */
	void resizeEvent(QResizeEvent* event);

private:
	Ui::PlaneBattleClass ui;
	QGraphicsView* m_pView;
};

#endif // TANKBATTLE_H
