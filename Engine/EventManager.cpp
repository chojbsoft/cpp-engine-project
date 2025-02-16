#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"

EventManager::EventManager() {}
EventManager::~EventManager() {}

void EventManager::Update()
{
	// 이전 프레임의 이벤트 처리에 등록해둔 dead obj 삭제
	_deadObjs.clear();

	// 이벤트 처리
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
		// Dead 상태로 변경
		// 삭제 
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
