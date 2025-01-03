#pragma once

class Player : public Object
{
	GENERATED_BODY(Player, Object)

public:
	virtual void Update();
	virtual void Render(HDC dc);
	
	void CreateMissile();
};

