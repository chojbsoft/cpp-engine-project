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

#define GENERATED_BODY(Type, BaseType)\
public:\
DEFINE_DEFAULT_CONSTRUCTOR_CALL(Type)\
static Class* StaticClass() { return staticClass;}\
static inline Class* staticClass = \
	RegisterEngineClass<Type>(L#Type);\
private:\
	using ThisClass = Type;\
	using Super = BaseType;\

#define DEFINE_DEFAULT_CONSTRUCTOR_CALL(TClass) \
	static void __DefaultConstructor(const ObjectInitializer& X) { new(X.GetObj())TClass; }


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
