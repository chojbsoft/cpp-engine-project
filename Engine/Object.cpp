#include "pch.h"
#include "Object.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "Collider.h"

Object::Object()
{
}

Object::~Object()
{
	if (_collider)
	{
		delete _collider;
	}
}

void Object::SetPos(Vec2 pos)
{
	this->_pos = pos;
}

void Object::SetScale(Vec2 scale)
{
	this->_scale = scale;
}

Vec2 Object::GetPos()
{
	return _pos;
}

Vec2 Object::GetScale()
{
	return _scale;
}

void Object::CreateCollider()
{
	_collider = new Collider(this);
}

void Object::Update()
{
}

void Object::UpdateLate()
{
	if (_collider)
	{
		_collider->UpdateLate();
	}
}

void Object::Render(HDC dc)
{
	Rectangle(dc
		, int(_pos._x - _scale._x / 2)
		, int(_pos._y - _scale._y / 2)
		, int(_pos._x + _scale._x / 2)
		, int(_pos._y + _scale._y / 2));
}
