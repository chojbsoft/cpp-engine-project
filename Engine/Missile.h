#pragma once
#include "Object.h"

class Missile 
	: public Object
{
public:
	Missile();
	~Missile();
	
public:
	virtual void Update();
	virtual void Render(HDC dc);

public:
	void SetDir(float theta)
	{
		this->theta = theta;
	}

	void SetDir(Vec2 dir)
	{
		this->dir = dir;
	}

private:
	// 방향이 아닌, 각도를 받음
	// x, y로 좌표를 구성하는 단위원이라 생각하고, 각도 받기
	// 즉 오른쪽으로 쏘고싶다면 0도, 왼쪽으로 쏘고싶다면 180도
	// 각도는 라디안으로 받음
	float theta;
	Vec2 dir;
};

