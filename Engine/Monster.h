#pragma once
#include "Object.h"

class Monster : public Object
{
public:
	Monster();

public:
	float GetSpeed(){ return _speed; }
	void SetSpeed(float speed) { speed = speed; }
	float GetMaxDixtance() { return _maxDistance; }
	void SetMaxDixtance(float dist) { _maxDistance = dist; }
	

public:
	virtual void Update();
	virtual void Render();

private:
	float _speed = 100.f;
	float _maxDistance = 50.f;
	
	// 1 -1
	int _dir = 1; 

};

