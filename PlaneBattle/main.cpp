#include "PlaneBattle.h"
#include "TGlobal.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// ȫ�ֳ�ʼ��
	if (CTGlobal::instance()->init())
	{
		TankBattle w;
		w.show();
	}
	return a.exec();
}
