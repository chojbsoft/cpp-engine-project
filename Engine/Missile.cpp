#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"

Missile::Missile()
    : theta(PI / 2.f), dir({ 0, 0 })
{
    dir.Normalize();
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
    vPos.x += 100.f * fDT * dir.x;
    vPos.y += 100.f * fDT * dir.y;
	SetPos(vPos);
}

void Missile::Render(HDC _dc)
{
    Vec2 vPos = GetPos();
    Vec2 vScale = GetScale();

    Ellipse(_dc
        , int(vPos.x - vScale.x / 2)
        , int(vPos.y - vScale.y / 2)
        , int(vPos.x + vScale.x / 2)
        , int(vPos.y + vScale.y / 2));
}
