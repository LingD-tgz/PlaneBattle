#pragma once
#include <TSingleton.h>
#include "TModelManager.h"
#include "TControler.h"

class CTGlobal : public CTSingleton<CTGlobal>
{
	friend class CTSingleton<CTGlobal>;
	CTGlobal(void);
public:
	~CTGlobal(void);

	/* ��ʼ�� */
	bool init();
	
	/* ��ȡģ�͹��� */
	CTModelManagerPtr getModelManager();

	/* ��ȡ������ */
	CTControlerPtr getControler();

private:
	CTModelManagerPtr m_modelManager; // ģ�͹���
	CTControlerPtr m_controler; // ������
};

