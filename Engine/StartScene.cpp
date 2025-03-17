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

	// ���� ��ġ
	int iMonCount = 5;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	Vec2 vResolution = Core::GetInst()->GetResolution();
	Monster* pMonsterObj = nullptr;

	// ���� �̵� ������ �������� ���� ���� ����, �¿쿡�� �� ��ũ���Ÿ��� ���� ���ϱ�
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
