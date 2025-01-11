#pragma once
class TimeManager
{
	SINGLE(TimeManager);

private:
	LARGE_INTEGER prevCount;
	LARGE_INTEGER curCount;
	LARGE_INTEGER frequency;

	double deltaTime;
	double acc;

	UINT callCount;
	UINT fps;

public:
	void Init();
	void Update();
	void Render();

public:
	double GetDT()
	{
		return deltaTime;
	}

	float GetfDT()
	{
		return deltaTime;
	}
};

