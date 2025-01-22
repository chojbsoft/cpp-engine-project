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
	// 현재 카운트
	QueryPerformanceCounter(&_prevCount);

	// 초당 카운트 횟수
	QueryPerformanceFrequency(&_frequency);
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&_curCount);

	// 델타 타임
	_deltaTime = (_curCount.QuadPart - _prevCount.QuadPart) 
		/ (double)_frequency.QuadPart;

	_prevCount = _curCount;
}

void TimeManager::Render()
{
	++_callCount;
	_acc += _deltaTime;

	// 1초가 지났을 때
	if (_acc >= 1)
	{
		_fps = _callCount;
		_acc = 0;
		_callCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d, DT: %f", _fps, _deltaTime);
		SetWindowText(Core::GetInst()->GetMainHwnd(), szBuffer);
	}
}

