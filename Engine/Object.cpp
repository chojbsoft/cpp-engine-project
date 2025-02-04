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


Collider* Object::GetCollider()
{
	return _collider;
}

void Object::CreateCollider(Vec2 offsetPos, Vec2 scale)
{
	_collider = new Collider(this, offsetPos, scale);
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

	RenderComponent(dc);
}

void Object::RenderComponent(HDC dc)
{
	if (_collider)
	{
		_collider->Render(dc);
	}
}

void Object::OnCollision(Collider* other)
{
}

void Object::OnCollisionBegin(Collider* other)
{
}

void Object::OnCollisionEnd(Collider* other)
{
}
