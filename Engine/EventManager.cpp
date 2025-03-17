#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"

EventManager::EventManager(){}
EventManager::~EventManager(){}

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

		// Dead ���·� ����
		// ���� 
		shared_ptr<Object>* deadObj = (shared_ptr<Object>*)(eve.lParam);
		(*deadObj)->SetDead();
		_deadObjs.push_back(*deadObj);
		delete deadObj;

		break;
	case EVENT_TYPE::SCENE_CHANGE:

		break;
	}

}
