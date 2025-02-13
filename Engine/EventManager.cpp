#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"

EventManager::EventManager(){}
EventManager::~EventManager(){}

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

void EventManager::Execute(const Event& eve)
{
	switch (eve.even)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam: shared_ptr<Object>*
		// wParam: GROUP_TYPE
		shared_ptr<Object>* obj = (shared_ptr<Object>*)eve.lParam;
		OBJECT_TYPE type = (OBJECT_TYPE)eve.wParam;
		SceneManager::GetInst()->GetCurScene()->AddObject(*obj, type);
		delete obj;

		break;
	}
	case EVENT_TYPE::DELETE_OBJECT:

		// Dead 상태로 변경
		// 삭제 
		shared_ptr<Object>* deadObj = (shared_ptr<Object>*)(eve.lParam);
		(*deadObj)->SetDead();
		_deadObjs.push_back(*deadObj);
		delete deadObj;

		break;
	case EVENT_TYPE::SCENE_CHANGE:

		break;
	}

}
