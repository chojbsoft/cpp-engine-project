#pragma once
#include "Texture.h"

class Player : public Object
{
public:
	Player();
	~Player();

public:

public:
	virtual void Update();
	virtual void Render(HDC dc);
	
	void CreateMissile();

private:
	Texture* mTex = nullptr;
};

