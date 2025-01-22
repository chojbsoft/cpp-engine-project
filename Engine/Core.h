#pragma once

class Core
{
	SINGLE(Core)

public:
	int Init(HWND hWnd, POINT ptResolution);
	void Progress();

public:
	HWND GetMainHwnd() { return _wnd; }
	POINT GetResolution() { return _resolution; }
	HDC GetMainDC() { return _dc; }
	HBRUSH GetBrush(BRUSH_TYPE type) { return Brushes[(UINT)type]; }
	HPEN GetPen(PEN_TYPE type) { return Pens[(UINT)type]; }

private:
	void CreateBrushPen();

private:
	HWND _wnd;
	POINT _resolution;
	HDC _dc;

	HBITMAP _bitmap;
	HDC _memDC;


private:
	// 자주 사용하는 GDI 
	HBRUSH Brushes[(UINT)BRUSH_TYPE::END];
	HPEN Pens[(UINT)PEN_TYPE::END];

};

