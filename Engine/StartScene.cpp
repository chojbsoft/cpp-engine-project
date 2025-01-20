#include "pch.h"
#include "StartScene.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Texture.h"
#include "PathManager.h"


void StartScene::Enter()
{
	// 임시
	shared = NewObject<Player>(3, 1.0f);
	Object* pObj = shared.get();


	pObj->SetPos({ 640, 384 });
	pObj->SetScale({ 100, 100 });

	AddObject(pObj, GROUP_TYPE::PLAYER);


	// 몬스터 배치
	int iMonCount = 5;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	Vec2 vResolution = Core::GetInst()->GetResolution();
	Monster* pMonsterObj = nullptr;

	// 한쪽 이동 범위와 스케일의 반을 더한 값을, 좌우에서 뺀 스크린거리로 간격 구하기
	float fTerm = (vResolution.x - (fMoveDist + fObjScale / 2) * 2) / (float)(iMonCount - 1);

	for (int i = 0; i < iMonCount; ++i)
	{
		pMonsterObj = new Monster();
		pMonsterObj->SetPos(Vec2((float)((fMoveDist + fObjScale / 2) + fTerm * i), 50.f));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetScale({ fObjScale, fObjScale });
		pMonsterObj->SetMaxDixtance(fMoveDist);
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}
}

void StartScene::Exit()
{
}
