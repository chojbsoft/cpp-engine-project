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
	// ���� ī��Ʈ
	QueryPerformanceCounter(&_prevCount);

	// �ʴ� ī��Ʈ Ƚ��
	QueryPerformanceFrequency(&_frequency);
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&_curCount);

	// ��Ÿ Ÿ��
	_deltaTime = (_curCount.QuadPart - _prevCount.QuadPart) 
		/ (double)_frequency.QuadPart;

	_prevCount = _curCount;
}

void TimeManager::Render()
{
	++_callCount;
	_acc += _deltaTime;

	// 1�ʰ� ������ ��
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

