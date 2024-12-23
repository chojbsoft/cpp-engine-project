#pragma once
#include "Object.h"

class Class : public ObjectBase
{
public:
	Class() = default;

public:
	void CreateDefaultObject();
	Object* GetDefaultObject(){ return classDefaultObject; }

public:
	wstring className;

private:
	Class* superClass;
	Object* classDefaultObject;

};

extern map<wstring, Class*> g_mapClass;

inline Class* RegisterEngineClass(wstring InClassName)
{
	// 메모리 할당
	ObjectBase* objectBase = (ObjectBase*)malloc(sizeof(Class));

	// UObjectBase 할당
	new(objectBase)ObjectBase(nullptr, EObjectFlags::RF_Class, nullptr);

	// UObjectBase의 기본생성자는 비워뒀기 때문에 한번더 Placement New로 생성해도됨
	Class* NewClass = new(objectBase)Class();

	NewClass->className = InClassName;
	g_mapClass.insert({ InClassName, NewClass });

	// CDO 생성
	NewClass->CreateDefaultObject();

	return NewClass;
}

