#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "PathManager.h"

Core::Core()
	: hWnd(0)
	, ptResolution{}
	, hDC(0)
{
}

Core::~Core()
{
	ReleaseDC(hWnd, hDC);

	DeleteDC(memDC);
	DeleteObject(hBitmap);
}

int Core::Init(HWND hWnd, POINT ptResolution)
{
	this->hWnd = hWnd;
	this->ptResolution = ptResolution;

	RECT rt{ 0, 0, ptResolution.x, ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(hWnd, nullptr, 0, 0
		, rt.right - rt.left, rt.bottom - rt.top, 0);

	hDC = GetDC(hWnd);

	hBitmap = CreateCompatibleBitmap(hDC, ptResolution.x, ptResolution.y);
	memDC = CreateCompatibleDC(hDC);

	HGDIOBJ hOldBit = SelectObject(memDC, hBitmap);
	DeleteObject(hOldBit);
	

	PathManager::GetInst()->Init();
	TimeManager::GetInst()->Init();
	KeyManager::GetInst()->Init();
	SceneManager::GetInst()->Init();


	return S_OK;
}

void Core::Progress()
{
	// Update
	TimeManager::GetInst()->Update();
	KeyManager::GetInst()->Update();
	SceneManager::GetInst()->Update();

	Rectangle(memDC, -1, -1, ptResolution.x + 1
		, ptResolution.y + 1);

	SceneManager::GetInst()->Render(memDC);

	BitBlt(hDC, 0, 0, ptResolution.x, ptResolution.y
		, memDC, 0, 0, SRCCOPY);

	//TimeManager::GetInst()->Render();
}