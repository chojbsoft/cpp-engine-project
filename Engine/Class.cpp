#include "pch.h"
#include "Class.h"

map<wstring, Class*> g_mapClass;

void Class::CreateDefaultObject()
{
	//_ASSERT(!classDefaultObject);

	//// shared_ptr�� �޸�Ǯ�� ����
	//const int SharedPtrSize = sizeof(_Ref_count_obj_alloc3 <Object
	//	, FAllocator<UObject>>) - sizeof(UObject);

	//// �޸�Ǯ ����
	//GUObjectArray.Create(ClassTypeInfo, SharedPtrSize + ClassSize);

	//// CDO ����
	//// ����ϰ� �ʱ�ȭ Ŭ������ ������ ���� 
	//FStaticConstructObjectParameters Params(this);
	//Params.SetFlags = RF_ClassDefaultObject;
	//Params.Name = ClassName;

	//// �ʱ�ȭ ���� ��ü
	//FObjectInitializer ObjectInitializer(Params);

	//// ���⼭ �ʱ�ȭ ����
	//ClassConstructor(ObjectInitializer);

	//ClassDefaultObject = ObjectInitializer.SharedObj;
	//return ClassDefaultObject.get();
}