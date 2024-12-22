#pragma once
#include "Object.h"

class Monster : public Object
{
private:
	Vec2 _centerPos = Vec2{ 0, 0 };
	float speed = 100.f;
	float maxDistance = 50.f;
	int dir = 1; // 1 -1

public:
	float GetSpeed(){ return speed; }
	void SetSpeed(float speed) { speed = speed; }

	void SetCenterPos(Vec2 pos) { _centerPos = pos;}
	float GetMaxDixtance() { return maxDistance; }
	void SetMaxDixtance(float dist) { maxDistance = dist; }
	

public:
	virtual void Update();
	virtual void Render();


};

