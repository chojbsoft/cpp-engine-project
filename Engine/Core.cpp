#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "SceneManager.h"

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

	// �ػ󵵿� �°� ������ ũ�� ����
	RECT rt{ 0, 0, ptResolution.x, ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(hWnd, nullptr, 0, 0
		, rt.right - rt.left, rt.bottom - rt.top, 0);

	// HDC ���
	hDC = GetDC(hWnd);

	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����
	hBitmap = CreateCompatibleBitmap(hDC, ptResolution.x, ptResolution.y);
	memDC = CreateCompatibleDC(hDC);

	HGDIOBJ hOldBit = SelectObject(memDC, hBitmap);
	DeleteObject(hOldBit);


	// Mgr �ʱ�ȭ
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

	// ȭ�� Ŭ����
	Rectangle(memDC, -1, -1, ptResolution.x + 1
		, ptResolution.y + 1);

	// �׸���
	SceneManager::GetInst()->Render(memDC);

	// ���
	BitBlt(hDC, 0, 0, ptResolution.x, ptResolution.y
		, memDC, 0, 0, SRCCOPY);
}