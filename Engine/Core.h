#pragma once

class Core
{
	SINGLE(Core)

public:
	int Init(HWND hWnd, POINT ptResolution);
	void Progress();

private:
	HWND mWnd;
	POINT mResolution;
	HDC mDC;

	HBITMAP mBitmap;
	HDC mMemDC;

public:
	HWND GetMainHwnd() { return mWnd; }
	POINT GetResolution() { return mResolution; }
	HDC GetMainDC() { return mDC; }
};

