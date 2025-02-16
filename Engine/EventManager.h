#pragma once

struct Event
{
	EVENT_TYPE even;

	// 범용적으로 사용하기 위한 파라미터
	DWORD_PTR lParam;
	DWORD_PTR wParam;
};

// shared_ptr에 대응하기 위한 임시 구조체
struct EventSharedObj : public Event
{
	shared_ptr<Object> sharedObj;
};

class EventManager
{
	SINGLE(EventManager)

public:
	void Update();

public:
	void AddEvent(const EventSharedObj& eve) { _events.push_back(eve); }

private:
	void Execute(const EventSharedObj& eve);

private:
	vector<EventSharedObj> _events;
	vector<shared_ptr<Object>> _deadObjs;
};

