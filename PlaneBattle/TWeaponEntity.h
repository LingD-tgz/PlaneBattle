#pragma once
#include "TEntity.h"

/* ����ʵ�� */
class CTWeaponEntity : public CTEntity
{
	/* ���˹�ģ */
	enum DamageScale
	{
		one_level=0, // һ���˺������
		two_level, // �����˺�
		three_level, // �����˺�����С��
	};

public:
	CTWeaponEntity(DamageScale damageScale);
	~CTWeaponEntity(void);

	/* ��ȡ�������˳̶� 
	   ���ݲ�ͬ�Ļ��˹�ģ��ȡ���Ļ��˳̶�Ҳ��ͬ
	   һ�����˹�ģ��0.8
	   �������˹�ģ��0.5
	   �������˹�ģ��0.2*/
	double getDamageDegree();

private:
	DamageScale m_damageScale;
};

