#include "pch.h"
#include "Collider.h"
#include "Core.h"
#include "SelectGDI.h"

Collider::Collider(Object* owner, Vec2 offsetPos, Vec2 scale)
	:_owner(owner), _offsetPos(offsetPos), _scale(scale)
{

}

void Collider::UpdateLate()
{
	_finalPos = _owner->GetPos() + _offsetPos;
}

void Collider::Render(HDC dc)
{
	// 소멸자에서 자동으로 반납하게 임시 객체 생성
	SelectGDI t1(dc, PEN_TYPE::GREEN);
	SelectGDI t2(dc, BRUSH_TYPE::HOLLOW);

	Rectangle(dc
		, int(_finalPos._x - _scale._x / 2)
		, int(_finalPos._y - _scale._y / 2)
		, int(_finalPos._x + _scale._x / 2)
		, int(_finalPos._y + _scale._y / 2));
}
