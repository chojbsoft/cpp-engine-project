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
	// ������ �ƴ�, ������ ����
	// x, y�� ��ǥ�� �����ϴ� �������̶� �����ϰ�, ���� �ޱ�
	// �� ���������� ���ʹٸ� 0��, �������� ���ʹٸ� 180��
	// ������ �������� ����
	float theta;
	Vec2 dir;
};

