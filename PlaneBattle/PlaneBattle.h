#ifndef TANKBATTLE_H
#define TANKBATTLE_H

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include "ui_PlaneBattle.h"

class TankBattle : public QMainWindow
{
	Q_OBJECT

public:
	TankBattle(QWidget *parent = 0);
	~TankBattle();

	void initWidget();

	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);

private slots:
	void controlerTimer();// �����ߵĶ�ʱ��
	void refreshTimer();// ˢ�¶�ʱ��

private:
	Ui::PlaneBattleClass ui;

	QTimer m_controlerTimer;// �����ߵĶ�ʱ��
	QTimer m_refreshTimer;// ˢ�¶�ʱ��

	bool m_bLeftMove;// ���Ʊ�־λ
	bool m_bRightMove;// ���Ʊ�־λ
	bool m_bUpMove;// ���Ʊ�־λ
	bool m_bDownMove;// ���Ʊ�־λ
};

#endif // TANKBATTLE_H
