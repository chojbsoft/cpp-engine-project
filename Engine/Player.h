#pragma once
#include "Object.h"

class Player : public Object
{
public:
	virtual void Update();
	virtual void Render(HDC dc);
	
	void CreateMissile();
};

