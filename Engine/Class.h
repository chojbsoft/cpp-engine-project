#pragma once
//#include "Object.h"

// Deprecated
//class Class : public ObjectBase
//{
//public:
//	Class() = delete;
//	Class(const type_info& InClassTypeInfo, const size_t InClassSize)
//		: typeInfo(InClassTypeInfo), classSize(InClassSize)
//	{
//	}
//
//public:
//	template <class T>
//	void CreateDefaultObject()
//	{
//		const int SharedPtrSize = sizeof(_Ref_count_obj_alloc3 <Object
//			, Allocator<Object>>) - sizeof(Object);
//
//		GObjectArray.Create(typeInfo, SharedPtrSize + classSize);
//
//		ObjectInitializer objectInitializer(this);
//
//		// CDO °´Ã¼ Ç¥½Ã
//		objectInitializer.ObjectFlags = EObjectFlags::RF_ClassDefaultObject;
//		objectInitializer.SharedObj = allocate_shared<T>(Allocator<T>(&objectInitializer));
//		classDefaultObject = objectInitializer.SharedObj;
//	}
//
//	shared_ptr<Object> GetDefaultObject() { return classDefaultObject; }
//
//public:
//	wstring className;
//	const type_info& typeInfo;
//	size_t classSize;
//
//private:
//	Class* superClass;
//	shared_ptr<Object> classDefaultObject;
//};
//
//extern map<wstring, Class*> g_mapClass;
//
//template<class T>
//inline Class* RegisterEngineClass(wstring InClassName)
//{
//	ObjectBase* objectBase = (ObjectBase*)malloc(sizeof(Class));
//
//	new(objectBase)ObjectBase(EObjectFlags::RF_Class);
//
//	Class* NewClass = new(objectBase)Class(typeid(T), sizeof(T));
//
//	NewClass->className = InClassName;
//	g_mapClass.insert({ InClassName, NewClass });
//
//	NewClass->CreateDefaultObject<T>();
//
//	return NewClass;
//}
