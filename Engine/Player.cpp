#include "pch.h"
#include "Player.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "Missile.h"
#include "Scene.h"
#include "SceneManager.h"
#include "PathManager.h"

Player::Player()
{
}

Player::~Player()
{
	if (mTex != nullptr)
	{
		delete mTex;
		mTex = nullptr;
	}
}

void Player::Init()
{
	// Texture ·Îµå
	mTex = new Texture;
	wstring strFilePath = PathManager::GetInst()->GetResourcePath();
	strFilePath += L"\\Texture\\Player.bmp";
	mTex->Load(strFilePath);
}

void Player::Update()
{
    Vec2 pos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		pos.y -= 200.f * DT;
	}
	if (KEY_HOLD(KEY::S))
	{
		pos.y += 200.f * DT;
	}
	if (KEY_HOLD(KEY::A))
	{
		pos.x -= 200.f * DT;
	}
	if (KEY_HOLD(KEY::D))
	{
		pos.x += 200.f * DT;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}

    SetPos(pos);
}

void Player::Render(HDC dc)
{
	Object::Render(dc);

}


void Player::CreateMissile()
{
    Vec2 vMissilePos = GetPos();
    vMissilePos.y -= GetScale().y / 2.f;

    Missile* pMissile = new Missile();
    pMissile->SetPos(vMissilePos);
    pMissile->SetScale(Vec2(25.f, 25.f));
    pMissile->SetDir(PI);

    pMissile->SetDir({ -1, -7 });

    Scene* pCurScene = SceneManager::GetInst()->GetCurScene();
    pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}
