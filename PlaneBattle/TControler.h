#pragma once
#include <QObject>

class CTControler : public QObject
{
	Q_OBJECT

public:
	CTControler(void);
	~CTControler(void);

	/* ��ʼ������ */
	void init();
};

typedef std::shared_ptr<CTControler> CTControlerPtr;

