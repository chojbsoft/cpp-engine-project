#pragma once
class Object
{
public:
	Object();
	virtual ~Object();

public:
	void SetPos(Vec2 pos);
	void SetScale(Vec2 scale);
	Vec2 GetPos();
	Vec2 GetScale();

public:
	virtual void Update() = 0;
	virtual void Render(HDC dc);

private:
	Vec2 pos;
	Vec2 scale;
};

