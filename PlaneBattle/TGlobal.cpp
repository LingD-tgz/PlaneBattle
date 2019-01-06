#include "TGlobal.h"

CTGlobal::CTGlobal(void)
{
}

CTGlobal::~CTGlobal(void)
{
}

bool CTGlobal::initApplication()
{
	/* ����ģ�͹��� */
	m_pModelManager = std::make_shared<CTModelManager>();

	/* �������� */
	m_pScene = std::make_shared<CTScene>();

	/* ���������� */
	m_pControler = std::make_shared<CTControler>();

	return true;
}

CTModelManagerPtr CTGlobal::getModelManager()
{
	return m_pModelManager;	
}

CTControlerPtr CTGlobal::getControler()
{
	return m_pControler;
}

CTScenePtr CTGlobal::getScene()
{
	return m_pScene;
}
