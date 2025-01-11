#include "pch.h"
#include "Texture.h"

void Texture::Load(const wstring& strFilePath)
{
	mBitmap = (HBITMAP)LoadImage(nullptr, strFilePath.c_str(), IMAGE_BITMAP
		, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(mBitmap);
	
}
