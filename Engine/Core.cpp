#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "PathManager.h"

Core::Core()
	: mWnd(0)
	, mResolution{}
	, mDC(0)
{
}

Core::~Core()
{
	ReleaseDC(mWnd, mDC);

	DeleteDC(m_hMemDC);
	DeleteObject(m_hBitmap);
}

int Core::Init(HWND hWnd, POINT ptResolution)
{
	this->mWnd = hWnd;
	this->mResolution = ptResolution;

	RECT rt{ 0, 0, ptResolution.x, ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(hWnd, nullptr, 0, 0
		, rt.right - rt.left, rt.bottom - rt.top, 0);

	mDC = GetDC(hWnd);

	m_hBitmap = CreateCompatibleBitmap(mDC, ptResolution.x, ptResolution.y);
	m_hMemDC = CreateCompatibleDC(mDC);

	HGDIOBJ hOldBit = SelectObject(m_hMemDC, m_hBitmap);
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

	Rectangle(m_hMemDC, -1, -1, mResolution.x + 1
		, mResolution.y + 1);

	SceneManager::GetInst()->Render(m_hMemDC);

	BitBlt(mDC, 0, 0, mResolution.x, mResolution.y
		, m_hMemDC, 0, 0, SRCCOPY);

	//TimeManager::GetInst()->Render();
}