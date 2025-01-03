#pragma once

enum class KEY_STATE
{
	TAP, 
	HOLD, 
	AWAY, 
	NONE, 
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,
	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,
	LAST
};

struct KeyInfo
{
	KEY_STATE eState;
	bool bPrev;
};


class KeyManager
{
	SINGLE(KeyManager);

public:
	void Init();
	void Update();

public:
	KEY_STATE GetKeyState(KEY eKey)
	{
		return vecKey[(int)eKey].eState;
	}

private:
	vector<KeyInfo> vecKey;
};

