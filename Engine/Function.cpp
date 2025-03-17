#include "pch.h"
#include "Function.h"
#include "EventManager.h"

void CreateObject(shared_ptr<Object>* obj, OBJECT_TYPE type)
{
	Event eve;
	eve.even = EVENT_TYPE::CREATE_OBJECT;
	eve.lParam = (DWORD_PTR)obj;
	eve.wParam = (DWORD_PTR)type;

	// �̺�Ʈ �߰�
	EventManager::GetInst()->AddEvent(eve);
}
