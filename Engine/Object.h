#pragma once
#include "ObjectBase.h"

class Object : public ObjectBase
{
public:
	Object();
	virtual ~Object();

public:
	// Object�� �����ڿ��� ObjectBase�� �÷��׸� Ȯ���� �� ����
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

