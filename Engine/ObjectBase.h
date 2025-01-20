#pragma once

class Class;
class Object;

// Deprecated
class ObjectBase /*: public std::enable_shared_from_this<ObjectBase>*/
{
public:
	ObjectBase();
	//ObjectBase(Class* InClass, EObjectFlags InObjectFlags, Object* InOuter)
	//	: MyClass(InClass)
	//	, ObjectFlags(InObjectFlags)
	//	, OuterPrivate(InOuter)
	//{

	//}

	ObjectBase(EObjectFlags InObjectFlags)
		: ObjectFlags(InObjectFlags)
	{

	}

	virtual ~ObjectBase(){}

	EObjectFlags GetFlags() const { return ObjectFlags; }
	//Object* GetOuter() const { return OuterPrivate; }
	//Class* GetClass() const { return MyClass; }

protected:
	EObjectFlags ObjectFlags;
	//Object* OuterPrivate;
	//Class* MyClass;

};

