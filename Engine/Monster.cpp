#include "pch.h"
#include "Monster.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "Collider.h"


Monster::Monster()
{
}

void Monster::OnCollisionBegin(Collider* other)
{
	if (other->GetOwner()->GetType() == OBJECT_TYPE::PROJ_PLAYER)
	{
		DestroyObject(GetShared(), GetType());
	}
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

void Monster::Render(HDC DC)
{
	Object::Render(DC);

}



