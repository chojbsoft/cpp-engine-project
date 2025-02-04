#include "pch.h"
#include "TimeManager.h"
#include "Core.h"
#include <stdio.h>

TimeManager::TimeManager()
{

}

TimeManager::~TimeManager()
{

}

void TimeManager::Init()
{
	QueryPerformanceCounter(&_prevCount);
	QueryPerformanceFrequency(&_frequency);
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&_curCount);
	_deltaTime = (_curCount.QuadPart - _prevCount.QuadPart) / (double)_frequency.QuadPart;
	_prevCount = _curCount;

	++_callCount;
	_acc += _deltaTime;
	if (_acc >= 1)
	{
		_fps = _callCount;
		_acc = 0;
		_callCount = 0;
	}
}

void TimeManager::Render()
{

}

