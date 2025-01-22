#include "pch.h"
#include "Collider.h"

Collider::Collider(Object* owner)
	:_owner(owner)
{

}

void Collider::UpdateLate()
{
	_finalPos = _owner->GetPos() + _offsetPos;
}
