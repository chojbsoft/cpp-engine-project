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

// Object 클래스들은 시작전 Class로 등록되기 위해
#define GENERATED_BODY(Type, BaseType)\
public:\
static Class* StaticClass() { return staticClass;}\
static inline Class* staticClass = \
	RegisterEngineClass(L#Type);\
private:\
	using ThisClass = Type;\
	using Super = BaseType;\

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


enum EObjectFlags
{
	RF_NoFlags = 0x00000000,
	RF_ClassDefaultObject = 0x00000010,
	RF_Class = 0x00000020
};