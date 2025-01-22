#pragma once

class Object;

class Collider
{
public:
	Collider(Object* owner);

public:
	void UpdateLate();

private:
	// 따라다니기 위해 소유자를 알아야함
	Object* _owner;
	Vec2 _offsetPos;

	// UpdateLate에서 계산
	Vec2 _finalPos;
	
};

