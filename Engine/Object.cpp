#include "pch.h"
#include "Object.h"
#include "KeyManager.h"
#include "TimeManager.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::SetPos(Vec2 pos)
{
    this->pos = pos;
}

void Object::SetScale(Vec2 scale)
{
    this->scale = scale;
}

Vec2 Object::GetPos()
{
    return pos;
}

Vec2 Object::GetScale()
{
    return scale;
}

void Object::Update()
{
}

void Object::Render(HDC dc)
{
    Rectangle(dc
        , int(pos.x - scale.x / 2)
        , int(pos.y - scale.y / 2)
        , int(pos.x + scale.x / 2)
        , int(pos.y + scale.y / 2));
}
