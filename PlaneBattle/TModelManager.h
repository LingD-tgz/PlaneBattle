#pragma once
#include "TEntity.h"
#include <QMutex>

class CTModelManager
{
public:
	CTModelManager(void);
	~CTModelManager(void);

	/* ��ȡʵ���б� */
	CTEntityList getEntityList();

	/* ���ʵ�� */
	void addEntity(CTEntityPtr entity);

	/* �Ƴ�ʵ�� */
	void removeEntity(CTEntityPtr entity);

	/* ����ID����ʵ�� */
	CTEntityPtr getEntityByID(GUID id);

private:
	CTEntityList m_entityList; // ʵ���б�
	QMutex m_mutex; // �ٽ���
};

typedef std::shared_ptr<CTModelManager> CTModelManagerPtr;

