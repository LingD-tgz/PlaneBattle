#include "TControler.h"
#include "TEntity.h"
#include "TGlobal.h"

CTControler::CTControler(void)
{
}

CTControler::~CTControler(void)
{
}

void CTControler::init()
{
	CTModelManagerPtr pModelManager = CTGlobal::instance()->getModelManager();
	CTScenePtr pScene = CTGlobal::instance()->getScene();
	if (pModelManager == nullptr || pScene == nullptr)
	{
		return;
	}

	// �����췽ʵ�壨�췽ʵ�����ڲ�������ֻ��һ����
	CTEntityPtr entity = std::make_shared<CTEntity>();
	entity->setCamp(CTEntity::Red); // ����ʵ����Ӫ
	entity->setPos(QPointF(0, 0)); // ����ʵ��λ��
	pModelManager->addEntity(entity); // ��ʵ����뵽ģ�͹�����
	pScene->addItemToScene(entity); // ���췽ʵ����뵽������
}
