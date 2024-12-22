#pragma once

enum class KEY_STATE
{
	TAP, // 막 누른 시점
	HOLD, // 누르고 있는
	AWAY, // 막 뗀 시점
	NONE, // 이전에도 눌리지 않음
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

	// 이전 프레임
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
	// 인덱스가 KEY
	vector<KeyInfo> vecKey;
};

