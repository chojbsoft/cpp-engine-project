#pragma once
#include "Core.h"
class SelectGDI
{
public:
	SelectGDI(HDC dc, PEN_TYPE type)
		: _dc(dc)
	{
		HPEN newPen = Core::GetInst()->GetPen(type);
		_defaultPen = (HPEN)SelectObject(dc, newPen);
	}

	SelectGDI(HDC dc, BRUSH_TYPE type)
		: _dc(dc)
	{
		HBRUSH newBrush = Core::GetInst()->GetBrush(type);
		_defaultBrush = (HBRUSH)SelectObject(dc, newBrush);
	}

	~SelectGDI()
	{
		if (_defaultPen)
		{
			SelectObject(_dc, _defaultPen);
		}

		if (_defaultBrush)
		{
			SelectObject(_dc, _defaultBrush);
		}
	}

private:
	HDC _dc;
	HPEN _defaultPen = nullptr;
	HBRUSH _defaultBrush = nullptr;
};

