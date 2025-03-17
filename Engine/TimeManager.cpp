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
	QueryPerformanceCounter(&prevCount);

	// �ʴ� ī��Ʈ Ƚ��
	QueryPerformanceFrequency(&frequency);
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&curCount);

	// ��Ÿ Ÿ��
	deltaTime = (curCount.QuadPart - prevCount.QuadPart) 
		/ (double)frequency.QuadPart;

	prevCount = curCount;

	++callCount;
	acc += deltaTime;

	// 1�ʰ� ������ ��
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

