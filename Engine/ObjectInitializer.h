#pragma once
class Class;
class Object;

struct ObjectInitializer
{
	Class* MyClass = nullptr;
	EObjectFlags ObjectFlags = RF_NoFlags;
	Object* OuterPrivate = nullptr;

	ObjectInitializer(Class* InClass)
		: MyClass(InClass)
	{
	}

	Object* GetObj() const { return Obj; }

	shared_ptr<Object> SharedObj;

	Object* Obj = nullptr;
};
