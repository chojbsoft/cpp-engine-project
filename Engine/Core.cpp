#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "PathManager.h"

Core::Core()
	: _wnd(0)
	, _resolution{}
	, _dc(0)
{
}

Core::~Core()
{
	ReleaseDC(_wnd, _dc);

	DeleteDC(_memDC);
	DeleteObject(_bitmap);
}

int Core::Init(HWND hWnd, POINT ptResolution)
{
	this->_wnd = hWnd;
	this->_resolution = ptResolution;

	RECT rt{ 0, 0, ptResolution.x, ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(hWnd, nullptr, 0, 0
		, rt.right - rt.left, rt.bottom - rt.top, 0);

	_dc = GetDC(hWnd);

	_bitmap = CreateCompatibleBitmap(_dc, ptResolution.x, ptResolution.y);
	_memDC = CreateCompatibleDC(_dc);

	HGDIOBJ hOldBit = SelectObject(_memDC, _bitmap);
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

	Rectangle(_memDC, -1, -1, _resolution.x + 1
		, _resolution.y + 1);

	SceneManager::GetInst()->Render(_memDC);

	BitBlt(_dc, 0, 0, _resolution.x, _resolution.y
		, _memDC, 0, 0, SRCCOPY);

	//TimeManager::GetInst()->Render();
}