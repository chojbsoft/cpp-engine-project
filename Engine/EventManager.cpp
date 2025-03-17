#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"

EventManager::EventManager() {}
EventManager::~EventManager() {}

void EventManager::Update()
{
	// ���� �������� �̺�Ʈ ó���� ����ص� dead obj ����
	for (int i = 0; i < _deadObjs.size(); ++i)
	{
		SceneManager::GetInst()->GetCurScene()->DeleteObject(_deadObjs[i], _deadObjs[i]->GetType());
	}
	_deadObjs.clear();

	// �̺�Ʈ ó��
	for (int i = 0; i < _events.size(); ++i)
	{
		Execute(_events[i]);
	}

	_events.clear();
}

void EventManager::Execute(const Event& eve)
{
	switch (eve.even)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		SceneManager::GetInst()->GetCurScene()->AddObject(eve.sharedObj, (OBJECT_TYPE)eve.wParam);

	}
	break;
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// Kill Pending ���·� �����
		shared_ptr<Object> obj = eve.sharedObj;
		obj->SetDead();
		_deadObjs.push_back(obj);

	}
	break;
	case EVENT_TYPE::SCENE_CHANGE:
	{
		SceneManager::GetInst()->ChangeScene((SCENE_TYPE)eve.lParam);
	}
	break;
	}

}
