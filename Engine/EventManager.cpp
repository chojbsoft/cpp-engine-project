#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"

EventManager::EventManager() {}
EventManager::~EventManager() {}

void EventManager::Update()
{
	// ���� �������� �̺�Ʈ ó���� ����ص� dead obj ����
	_deadObjs.clear();

	// �̺�Ʈ ó��
	for (int i = 0; i < _events.size(); ++i)
	{
		Execute(_events[i]);
	}

	_events.clear();
}

void EventManager::Execute(const EventSharedObj& eve)
{
	switch (eve.even)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		SceneManager::GetInst()->GetCurScene()->AddObject(eve.sharedObj, (OBJECT_TYPE)eve.wParam);

		break;
	}
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// Dead ���·� ����
		// ���� 
		shared_ptr<Object> obj = ((EventSharedObj)eve).sharedObj;
		obj->SetDead();
		SceneManager::GetInst()->GetCurScene()->DeleteObject(eve.sharedObj, (OBJECT_TYPE)eve.wParam);
		_deadObjs.push_back(obj);

		break;
	}
	case EVENT_TYPE::SCENE_CHANGE:

		break;
	}

}
