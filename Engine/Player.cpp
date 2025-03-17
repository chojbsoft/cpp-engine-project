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
		pos._y -= 500.f * DT;
	}
	if (KEY_HOLD(KEY::S))
	{
		pos._y += 500.f * DT;
	}
	if (KEY_HOLD(KEY::A))
	{
		pos._x -= 500.f * DT;
	}
	if (KEY_HOLD(KEY::D))
	{
		pos._x += 500.f * DT;
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
	int x = Pos._x - (width / 2);
	int y = Pos._y - (height / 2);
	
	// ���ϴ� �ȼ��� �����ϱ� ����
	TransparentBlt(dc, x, y, width, height, mTex->GetDC(), 0, 0, width, height, RGB(255, 0, 255));

	// ������Ʈ ������
	RenderComponent(dc);
}


void Player::CreateMissile()
{
	shared_ptr<Missile> missile = NewObject<Missile>();

    Vec2 missilePos = GetPos();
    missilePos._y -= GetScale()._y / 2.f;
    missile->SetPos(missilePos);
    missile->SetScale(Vec2(25.f, 25.f));
    missile->SetDir(PI);
    missile->SetDir({ -1, -7 });
	missile->CreateCollider(Vec2::Zero(), missile->GetScale());
	missile->SetType(OBJECT_TYPE::PROJ_PLAYER);

	// ���� �����ϰ� �ּ� �ѱ�
	// Event �Ķ���� ũ���� 8����Ʈ�� ���߰�, �̺�Ʈ�Ŵ��� Update���� �Ҹ���� �ʰ� �ϱ� ����
	//shared_ptr<Object>* obj = new shared_ptr<Object>(missile);

	CreateObject(missile, OBJECT_TYPE::PROJ_PLAYER);
}
