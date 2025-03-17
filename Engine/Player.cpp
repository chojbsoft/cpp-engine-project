#include "pch.h"
#include "Player.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "Missile.h"
#include "Scene.h"
#include "SceneManager.h"
#include "PathManager.h"
#include "ResourceManager.h"

Player::Player()
{
	// Texture �ε�
	mTex = ResourceManager::GetInst()->Load(L"Player", L"\\Texture\\Player.bmp");
}

Player::~Player()
{
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
	// �����ϸ��� ������, BitBlt������ ������ �� �� �ֱ� ������, �����÷ο�� �� ����
	int width = mTex->GetWidth();
	int height = mTex->GetHeight();

	// �»�� ��ǥ
	Vec2 Pos = GetPos();
	int x = Pos.x - (width / 2);
	int y = Pos.y - (height / 2);
	
	// ���ϴ� �ȼ��� �����ϱ� ����
	TransparentBlt(dc, x, y, width, height, mTex->GetDC(), 0, 0, width, height, RGB(255, 0, 255));
}


void Player::CreateMissile()
{
    Vec2 vMissilePos = GetPos();
    vMissilePos.y -= GetScale().y / 2.f;

	shared_ptr<Missile> pMissile = NewObject<Missile>();
    pMissile->SetPos(vMissilePos);
    pMissile->SetScale(Vec2(25.f, 25.f));
    pMissile->SetDir(PI);

    pMissile->SetDir({ -1, -7 });

    Scene* pCurScene = SceneManager::GetInst()->GetCurScene();
    pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}
