#pragma once
#include "TEntity.h"
#include <QString>

/* �ɻ�ʵ�� */
class CTPlaneEntity : public CTEntity
{
public:
	CTPlaneEntity(void);
	~CTPlaneEntity(void);

	/* ʵ������ֵ */
	int getHealth();
	void setHealth(int health);

	/* �Ƿ����(����ֵ�Ƿ�Ϊ0) */
	bool isDestory();

private:
	int m_health; // ʵ������ֵ
};

