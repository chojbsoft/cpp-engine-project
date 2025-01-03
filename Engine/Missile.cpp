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

    // 위로 갈수록 y가 플러스인 좌표계를 기준으로 각도를 받았기 때문에
    // y는 역수로 더해주기
	//vPos.x += 200.f * fDT * cosf(m_fTheta);
    //vPos.y -= 200.f * fDT * sinf(m_fTheta);

    // 정규화가 된 방향벡터이기 때문에, x는 cos, y는 sin
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
