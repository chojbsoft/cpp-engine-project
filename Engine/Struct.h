#pragma once

struct Vec2
{
	float x;
	float y;

public:
	Vec2& operator=(POINT _pt)
	{
		x = _pt.x;
		y = _pt.y;
	}

	Vec2(){ }

	Vec2(int _x, int _y)
		:x(_x), y(_y)
	{

	}

	Vec2(float _x, float _y)
		:x(_x), y(_y)
	{

	}

	Vec2(const POINT& _pt)
		: x(_pt.x), y(_pt.y)
	{
	}

public:
	double Length()
	{
		return sqrt(x * x + y * y);
	}

	Vec2 Normalize()
	{
		double len = Length();
		x /= len;
		y /= len;

		return *this;
	}
	
};
