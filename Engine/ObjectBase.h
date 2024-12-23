#pragma once

class Class;
class Object;

class ObjectBase
{
public:
	ObjectBase() = default;
	ObjectBase(Class* InClass, EObjectFlags InObjectFlags, Object* InOuter)
		: MyClass(InClass)
		, ObjectFlags(InObjectFlags)
		, OuterPrivate(InOuter)
	{
	}

	virtual ~ObjectBase(){}

	EObjectFlags GetFlags() const { return ObjectFlags; }
	Object* GetOuter() const { return OuterPrivate; }
	Class* GetClass() const { return MyClass; }

protected:
	EObjectFlags ObjectFlags;
	Object* OuterPrivate;
	Class* MyClass;

};

