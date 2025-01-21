#pragma once
#include "GameResource.h"
class Texture :
	public GameResource
{
public:
	void Load(const wstring& strFilePath);

public:
	UINT GetWidth() { return mBitmapInfo.bmWidth; }
	UINT GetHeight() { return mBitmapInfo.bmHeight; }
	HDC GetDC() { return mDC; }

private:
	Texture(wstring strKey, wstring strRelPath)
		: GameResource(strKey, strRelPath)
	{
	}

	Texture() {}
	~Texture() {}

	friend class ResourceManager;

private:
	// 텍스처는 픽셀데이터와 DC로 이루어져 있음
	HDC mDC;
	HBITMAP mBitmap;

private:
	BITMAP mBitmapInfo;

};

