#pragma once
#include "ObjectBase.h"

class Object : public ObjectBase
{
public:
	Object();
	virtual ~Object();

public:
	// Object의 생성자에서 ObjectBase의 플래그를 확인할 수 있음
	bool HasAnyFlags(const EObjectFlags Flag) const
	{
		return (GetFlags() & Flag) != 0;
	}

public:
	void SetPos(Vec2 pos);
	void SetScale(Vec2 scale);
	Vec2 GetPos();
	Vec2 GetScale();

public:
	virtual void Update() = 0;
	virtual void Render(HDC dc);

private:
	Vec2 pos;
	Vec2 scale;
};

