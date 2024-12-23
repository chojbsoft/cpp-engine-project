#pragma once

class Player : public Object
{
public:
	GENERATED_BODY(Player, Object)

public:
	virtual void Update();
	virtual void Render(HDC dc);
	
	void CreateMissile();
};

