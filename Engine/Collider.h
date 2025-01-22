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
	Object* owner;
	friend class Object;
};

