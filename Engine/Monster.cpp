#include "pch.h"
#include "Monster.h"
#include "TimeManager.h"


Monster::Monster()
{
}

void Monster::Update()
{
	Vec2 vCurPos = GetPos();
	vCurPos._x += DT * speed * dir;

	float fDist = abs(vCurPos._x - _centerPos._x) - maxDistance;
	if (fDist > 0)
	{
		dir *= -1;
		vCurPos._x += fDist * dir;
	}
	SetPos(vCurPos);
}

void Monster::Render()
{

}

