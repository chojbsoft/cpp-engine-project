#include "pch.h"
#include "Function.h"
#include "EventManager.h"

void CreateObject(shared_ptr<Object> obj, OBJECT_TYPE type)
{
	EventSharedObj eve;
	eve.even = EVENT_TYPE::CREATE_OBJECT;
	eve.wParam = (DWORD_PTR)type;
	eve.sharedObj = obj;

	// 이벤트 추가
	EventManager::GetInst()->AddEvent(eve);
}

void DestroyObject(shared_ptr<Object> obj, OBJECT_TYPE type)
{
	EventSharedObj eve;
	eve.even = EVENT_TYPE::DELETE_OBJECT;
	eve.wParam = (DWORD_PTR)type;
	eve.sharedObj = obj;

	// 이벤트 추가
	EventManager::GetInst()->AddEvent(eve);
}