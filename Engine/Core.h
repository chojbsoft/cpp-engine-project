#pragma once

class Core
{
	SINGLE(Core)

public:
	int Init(HWND hWnd, POINT ptResolution);
	void Progress();

private:
	HWND _wnd;
	POINT _resolution;
	HDC _dc;

	HBITMAP _bitmap;
	HDC _memDC;

public:
	HWND GetMainHwnd() { return _wnd; }
	POINT GetResolution() { return _resolution; }
	HDC GetMainDC() { return _dc; }
};

