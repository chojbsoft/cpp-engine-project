#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"

EventManager::EventManager() {}
EventManager::~EventManager() {}

void EventManager::Update()
{
	// 이전 프레임의 이벤트 처리에 등록해둔 dead obj 삭제
	for (int i = 0; i < _deadObjs.size(); ++i)
	{
		SceneManager::GetInst()->GetCurScene()->DeleteObject(_deadObjs[i], _deadObjs[i]->GetType());
	}
	_deadObjs.clear();

	// 이벤트 처리
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
		// Kill Pending 상태로 만들기
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
