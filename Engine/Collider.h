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
	// ����ٴϱ� ���� �����ڸ� �˾ƾ���
	Object* _owner;
	Vec2 _offsetPos;
	Vec2 _scale;

	// UpdateLate���� ���
	Vec2 _finalPos;
	
};

