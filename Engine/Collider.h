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
	Object* owner;
	friend class Object;
};

