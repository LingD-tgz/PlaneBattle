#pragma once
#include "TSingleton.h"
#include "TModelManager.h"
#include "TControler.h"
#include "TScene.h"

class CTGlobal : public CTSingleton<CTGlobal>
{
	friend class CTSingleton<CTGlobal>;
	CTGlobal(void);
public:
	~CTGlobal(void);

	/* ��ʼ�� */
	bool initApplication();
	
	/* ��ȡģ�͹��� */
	CTModelManagerPtr getModelManager();

	/* ��ȡ������ */
	CTControlerPtr getControler();

	/* ��ȡ���� */
	CTScenePtr getScene();

private:
	CTModelManagerPtr m_pModelManager; // ģ�͹���
	CTControlerPtr m_pControler; // ������
	CTScenePtr m_pScene; // ����
};

