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
	// Texture 로드
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
		pos._y -= 200.f * DT;
	}
	if (KEY_HOLD(KEY::S))
	{
		pos._y += 200.f * DT;
	}
	if (KEY_HOLD(KEY::A))
	{
		pos._x -= 200.f * DT;
	}
	if (KEY_HOLD(KEY::D))
	{
		pos._x += 200.f * DT;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}

    SetPos(pos);
}

void Player::Render(HDC dc)
{
	// 음수일리는 없지만, BitBlt에서는 음수가 들어갈 수 있기 때문에, 오버플로우될 수 있음
	int width = mTex->GetWidth();
	int height = mTex->GetHeight();

	// 좌상단 좌표
	Vec2 Pos = GetPos();
	int x = Pos._x - (width / 2);
	int y = Pos._y - (height / 2);
	
	// 원하는 픽셀만 복사하기 위해
	TransparentBlt(dc, x, y, width, height, mTex->GetDC(), 0, 0, width, height, RGB(255, 0, 255));

	// 컴포넌트 렌더링
	RenderComponent(dc);
}


void Player::CreateMissile()
{
    Vec2 vMissilePos = GetPos();
    vMissilePos._y -= GetScale()._y / 2.f;

	shared_ptr<Missile> pMissile = NewObject<Missile>();
	pMissile->CreateCollider();

    pMissile->SetPos(vMissilePos);
    pMissile->SetScale(Vec2(25.f, 25.f));
    pMissile->SetDir(PI);

    pMissile->SetDir({ -1, -7 });

    Scene* pCurScene = SceneManager::GetInst()->GetCurScene();
    pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}
