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
	// �޸� �Ҵ�
	ObjectBase* objectBase = (ObjectBase*)malloc(sizeof(Class));

	// UObjectBase �Ҵ�
	new(objectBase)ObjectBase(nullptr, EObjectFlags::RF_Class, nullptr);

	// UObjectBase�� �⺻�����ڴ� ����ױ� ������ �ѹ��� Placement New�� �����ص���
	Class* NewClass = new(objectBase)Class();

	NewClass->className = InClassName;
	g_mapClass.insert({ InClassName, NewClass });

	// CDO ����
	NewClass->CreateDefaultObject();

	return NewClass;
}

