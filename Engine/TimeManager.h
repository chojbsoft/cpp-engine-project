#pragma once
class TimeManager
{
	SINGLE(TimeManager);

public:
	void Init();
	void Update();
	void Render();

public:
	double GetDT()
	{
		return _deltaTime;
	}

	float GetfDT()
	{
		return _deltaTime;
	}

private:
	LARGE_INTEGER _prevCount;
	LARGE_INTEGER _curCount;
	LARGE_INTEGER _frequency;

	double _deltaTime;
	double _acc;

	UINT _callCount;
	UINT _fps;

};

