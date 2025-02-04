#pragma once

#define SINGLE(type)\
public:\
	static type* GetInst()\
	{\
		static type manager;\
		return &manager;\
	}\
private:\
	type();\
	~type();\


#define DT TimeManager::GetInst()->GetDT()
#define fDT TimeManager::GetInst()->GetDT()

#define PI 3.1415926535f

#define KEY_CHECK(key, state) KeyManager::GetInst()->GetKeyState(key) == state
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)


enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MISSILE,
	MONSTER,



	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,


	END
};

enum class BRUSH_TYPE
{
	HOLLOW,


	END
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,


	END
};

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	END,
};