#include "pch.h"
#include "Monster.h"
#include "TimeManager.h"


Monster::Monster()
{
}

void Monster::Update()
{
	Vec2 vCurPos = GetPos();
	vCurPos.x += DT * speed * dir;

	float fDist = abs(vCurPos.x - _centerPos.x) - maxDistance;
	if (fDist > 0)
	{
		dir *= -1;
		vCurPos.x += fDist * dir;
	}
	SetPos(vCurPos);
}

void Monster::Render()
{

}

