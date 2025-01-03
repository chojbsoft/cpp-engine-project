#pragma once
#include "Object.h"
#include "ObjectArray.h"

class Class : public ObjectBase
{
public:
	Class() = delete;
	Class(const type_info& InClassTypeInfo, const size_t InClassSize)
		: typeInfo(InClassTypeInfo), classSize(InClassSize)
	{ }

public:
	template <class T>
	void CreateDefaultObject()
	{
		const int SharedPtrSize = sizeof(_Ref_count_obj_alloc3 <Object
			, Allocator<Object>>) - sizeof(Object);

		GObjectArray.Create(typeInfo, SharedPtrSize + classSize);

		ObjectInitializer objectInitializer(this);

		objectInitializer.SharedObj = allocate_shared<T>(Allocator<T>(&objectInitializer));
		classDefaultObject = objectInitializer.SharedObj.get();
	}

	Object* GetDefaultObject() { return classDefaultObject; }

public:
	wstring className;
	const type_info& typeInfo;
	size_t classSize;

private:
	Class* superClass;
	Object* classDefaultObject;
};

extern map<wstring, Class*> g_mapClass;

template<class T>
inline Class* RegisterEngineClass(wstring InClassName)
{
	ObjectBase* objectBase = (ObjectBase*)malloc(sizeof(Class));

	new(objectBase)ObjectBase(nullptr, EObjectFlags::RF_Class, nullptr);

	Class* NewClass = new(objectBase)Class(typeid(T), sizeof(T));

	NewClass->className = InClassName;
	g_mapClass.insert({ InClassName, NewClass });

	NewClass->CreateDefaultObject<T>();

	return NewClass;
}

