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
	QueryPerformanceCounter(&prevCount);

	// 초당 카운트 횟수
	QueryPerformanceFrequency(&frequency);
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&curCount);

	// 델타 타임
	deltaTime = (curCount.QuadPart - prevCount.QuadPart) 
		/ (double)frequency.QuadPart;

	prevCount = curCount;

	++callCount;
	acc += deltaTime;

	// 1초가 지났을 때
	if (acc >= 1)
	{
		fps = callCount;
		acc = 0;
		callCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d, DT: %f", fps, deltaTime);
		SetWindowText(Core::GetInst()->GetMainHwnd(), szBuffer);
	}
}

