#pragma once

struct Event
{
	EVENT_TYPE even;

	// 범용적으로 사용하기 위한 파라미터
	DWORD_PTR lParam;
	DWORD_PTR wParam;
};

class EventManager
{
	SINGLE(EventManager)

public:
	void Update();

public:
	void AddEvent(const Event& eve) { _events.push_back(eve); }

private:
	void Execute(const Event& eve);

private:
	vector<Event> _events;
	vector<shared_ptr<Object>> _deadObjs;
};

