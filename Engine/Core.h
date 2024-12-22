#pragma once

class Core
{
	SINGLE(Core)

public:
	int Init(HWND hWnd, POINT ptResolution);
	void Progress();

private:
	HWND hWnd;
	POINT ptResolution;
	HDC hDC;

	// 더블버퍼링
	HBITMAP hBitmap;
	HDC memDC;

public:
	HWND GetMainHwnd() { return hWnd; }
	POINT GetResolution() { return ptResolution; }
};

