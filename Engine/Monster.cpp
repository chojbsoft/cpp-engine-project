#include "pch.h"
#include "Monster.h"
#include "TimeManager.h"


Monster::Monster()
{
}

void Monster::Update()
{
	return;
	Vec2 vCurPos = GetPos();
	vCurPos._x += DT * _speed * _dir;

	float fDist = abs(vCurPos._x - _pos._x) - _maxDistance;
	if (fDist > 0)
	{
		_dir *= -1;
		vCurPos._x += fDist * _dir;
	}
	SetPos(vCurPos);
}

void Monster::Render()
{

}

