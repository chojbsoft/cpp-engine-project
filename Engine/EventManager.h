#pragma once

struct Event
{
	EVENT_TYPE even;
	DWORD lParam;
	DWORD wParam;
};

class EventManager
{
	SINGLE(EventManager)

public:
	void Update();

private:
	vector<Event> vec;
};

