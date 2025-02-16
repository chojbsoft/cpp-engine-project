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
	virtual void OnCollisionBegin(Collider* other);

public:
	virtual void Update();
	virtual void Render(HDC DC) override;

private:
	float _speed = 100.f;
	float _maxDistance = 50.f;
	
	// 1 -1
	int _dir = 1; 

};

