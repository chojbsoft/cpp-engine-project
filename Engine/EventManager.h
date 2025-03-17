#pragma once

struct Event
{
	EVENT_TYPE even;

	// ���������� ����ϱ� ���� �Ķ����
	DWORD_PTR lParam;
	DWORD_PTR wParam;
};

// shared_ptr�� �����ϱ� ���� �ӽ� ����ü
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

