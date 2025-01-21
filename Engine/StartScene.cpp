#include "pch.h"
#include "StartScene.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Texture.h"
#include "PathManager.h"


void StartScene::Enter()
{
	shared_ptr<Object> player = NewObject<Player>();

	player->SetPos({ 640, 384 });
	player->SetScale({ 100, 100 });

	AddObject(player, GROUP_TYPE::PLAYER);

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
		shared_ptr<Monster> monster = NewObject<Monster>();
		monster->SetPos(Vec2((float)((fMoveDist + fObjScale / 2) + fTerm * i), 50.f));
		monster->SetCenterPos(monster->GetPos());
		monster->SetScale({ fObjScale, fObjScale });
		monster->SetMaxDixtance(fMoveDist);
		AddObject(monster, GROUP_TYPE::MONSTER);
	}
}

void StartScene::Exit()
{
}
