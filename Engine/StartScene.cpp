#include "pch.h"
#include "StartScene.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Texture.h"
#include "PathManager.h"
#include "CollisionManager.h"


void StartScene::Enter()
{
	shared_ptr<Object> player = NewObject<Player>();

	player->SetPos({ 640, 384 });
	player->SetScale({ 100, 100 });
	player->CreateCollider(Vec2::Zero(), player->GetScale() / 2.0f);

	AddObject(player, OBJECT_TYPE::PLAYER);

	// 몬스터 배치
	int cnt = 2;
	float dist = 25.f;
	float objScale = 50.f;
	Vec2 resolution = Core::GetInst()->GetResolution();
	Monster* monster = nullptr;

	// 한쪽 이동 범위와 스케일의 반을 더한 값을, 좌우에서 뺀 스크린거리로 간격 구하기
	float term = (resolution._x - (dist + objScale / 2) * 2) / (float)(cnt - 1);

	for (int i = 0; i < cnt; ++i)
	{
		shared_ptr<Monster> monster = NewObject<Monster>();
		monster->SetPos(Vec2((float)((dist + objScale / 2) + term * i), 50.f));
		monster->SetScale({ objScale, objScale });
		monster->SetMaxDixtance(dist);
		monster->CreateCollider(Vec2::Zero(), monster->GetScale() / 2.0f);

		AddObject(monster, OBJECT_TYPE::MONSTER);
	}

	CollisionManager::GetInst()->CheckGroup(OBJECT_TYPE::PLAYER, OBJECT_TYPE::MONSTER);
}

void StartScene::Exit()
{
	// 씬에서 지정되어 있던 충돌체 그룹 설정 해제
	CollisionManager::GetInst()->Reset();
}
