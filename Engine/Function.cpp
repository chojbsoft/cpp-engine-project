#include "pch.h"
#include "Function.h"
#include "EventManager.h"

void CreateObject(shared_ptr<Object>* obj, OBJECT_TYPE type)
{
	Event eve;
	eve.even = EVENT_TYPE::CREATE_OBJECT;
	eve.lParam = (DWORD_PTR)obj;
	eve.wParam = (DWORD_PTR)type;

	// 이벤트 추가
	EventManager::GetInst()->AddEvent(eve);
}
