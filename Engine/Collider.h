#pragma once

class Object;

class Collider
{
public:
	Collider(Object* owner, Vec2 offsetPos, Vec2 scale);

public:
	void UpdateLate();
	void Render(HDC dc);

private:
	// 따라다니기 위해 소유자를 알아야함
	Object* _owner;
	Vec2 _offsetPos;
	Vec2 _scale;

	// UpdateLate에서 계산
	Vec2 _finalPos;
	
};

