#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"

Missile::Missile()
    : _theta(PI / 2.f), _dir({ 0, 0 })
{
    _dir.Normalize();
}
  
Missile::~Missile()
{
}

void Missile::Update()
{
	Vec2 vPos = GetPos();

    // ���� ������ y�� �÷����� ��ǥ�踦 �������� ������ �޾ұ� ������
    // y�� ������ �����ֱ�
	//vPos.x += 200.f * fDT * cosf(m_fTheta);
    //vPos.y -= 200.f * fDT * sinf(m_fTheta);

    // ����ȭ�� �� ���⺤���̱� ������, x�� cos, y�� sin
    vPos._x += 100.f * fDT * _dir._x;
    vPos._y += 100.f * fDT * _dir._y;
	SetPos(vPos);
}

void Missile::Render(HDC _dc)
{
    Vec2 vPos = GetPos();
    Vec2 vScale = GetScale();

    Ellipse(_dc
        , int(vPos._x - vScale._x / 2)
        , int(vPos._y - vScale._y / 2)
        , int(vPos._x + vScale._x / 2)
        , int(vPos._y + vScale._y / 2));
}
