#include "pch.h"
#include "Collider.h"
#include "Core.h"
#include "SelectGDI.h"

Collider::Collider(Object* owner, Vec2 offsetPos, Vec2 scale)
	:_owner(owner), _offsetPos(offsetPos), _scale(scale), _ID(_nextID++)
{

}

Collider::Collider(const Collider& other)
	:_owner(nullptr), _offsetPos(other._offsetPos), _scale(other._scale), _ID(_nextID++)
{
}

void Collider::UpdateLate()
{
	_finalPos = _owner->GetPos() + _offsetPos;
}

void Collider::Render(HDC dc)
{
	PEN_TYPE penType = PEN_TYPE::GREEN;
	if (_isColliding)
	{
		penType = PEN_TYPE::RED;
	}

	// 소멸자에서 자동으로 반납하게 임시 객체 생성
	SelectGDI t1(dc, penType); 
	SelectGDI t2(dc, BRUSH_TYPE::HOLLOW);

	Rectangle(dc
		, int(_finalPos._x - _scale._x / 2)
		, int(_finalPos._y - _scale._y / 2)
		, int(_finalPos._x + _scale._x / 2)
		, int(_finalPos._y + _scale._y / 2));
}

void Collider::OnCollision(Collider* other)
{
	
}

void Collider::OnCollisionEnter(Collider* other)
{
	++_isColliding;
}

void Collider::OnCollisionEnd(Collider* other)
{
	--_isColliding;
}
