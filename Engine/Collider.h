#pragma once

class Object;

class Collider
{
public:
	Collider(Object* owner);

public:
	void UpdateLate();

private:
	// ����ٴϱ� ���� �����ڸ� �˾ƾ���
	Object* _owner;
	Vec2 _offsetPos;

	// UpdateLate���� ���
	Vec2 _finalPos;
	
};

