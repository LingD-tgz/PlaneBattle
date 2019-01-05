#include "TGlobal.h"

CTGlobal::CTGlobal(void)
{
}

CTGlobal::~CTGlobal(void)
{
}

bool CTGlobal::init()
{
	/* ����ģ�͹��� */
	m_modelManager = std::make_shared<CTModelManager>();

	/* ���������� */
	m_controler = std::make_shared<CTControler>();
	m_controler->init(); // ��������ʼ��

	return true;
}

CTModelManagerPtr CTGlobal::getModelManager()
{
	return m_modelManager;	
}

CTControlerPtr CTGlobal::getControler()
{
	return m_controler;
}
