#pragma once

struct Vec2
{
public:
	Vec2(){ }

	Vec2(int x, int y)
		:_x(x), _y(y)
	{

	}

	Vec2(float x, float y)
		:_x(x), _y(y)
	{

	}

	Vec2(const POINT& pt)
		: _x(pt.x), _y(pt.y)
	{
	}

public:
	Vec2& operator=(POINT pt)
	{
		_x = pt.x;
		_y = pt.y;
	}

	Vec2 operator+(Vec2 other)
	{
		return Vec2(_x + other._x, _y + other._y);
	}

	Vec2 operator-(Vec2 other)
	{
		return Vec2(_x - other._x, _y - other._y);
	}

	Vec2 operator*(float other)
	{
		return Vec2(_x * other, _y * other);
	}

	Vec2 operator/(float other)
	{
		return Vec2(_x / other, _y / other);
	}

public:
	double Length()
	{
		return sqrt(_x * _x + _y * _y);
	}

	Vec2 Normalize()
	{
		double len = Length();
		_x /= len;
		_y /= len;

		return *this;
	}

	static Vec2 Zero()
	{
		return Vec2(0, 0);
	}

public:
	float _x;
	float _y;

};
