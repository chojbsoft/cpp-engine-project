#include "pch.h"
#include "Class.h"

map<wstring, Class*> g_mapClass;

void Class::CreateDefaultObject()
{
	//_ASSERT(!classDefaultObject);

	//// shared_ptr도 메모리풀에 포함
	//const int SharedPtrSize = sizeof(_Ref_count_obj_alloc3 <Object
	//	, FAllocator<UObject>>) - sizeof(UObject);

	//// 메모리풀 생성
	//GUObjectArray.Create(ClassTypeInfo, SharedPtrSize + ClassSize);

	//// CDO 생성
	//// 깔끔하게 초기화 클래스에 데이터 전달 
	//FStaticConstructObjectParameters Params(this);
	//Params.SetFlags = RF_ClassDefaultObject;
	//Params.Name = ClassName;

	//// 초기화 수행 객체
	//FObjectInitializer ObjectInitializer(Params);

	//// 여기서 초기화 수행
	//ClassConstructor(ObjectInitializer);

	//ClassDefaultObject = ObjectInitializer.SharedObj;
	//return ClassDefaultObject.get();
}