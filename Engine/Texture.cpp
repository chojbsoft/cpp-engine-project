#include "pch.h"
#include "Texture.h"
#include "Core.h"

void Texture::Load(const wstring& strFilePath)
{
	// 이미지를 Bitmap으로 로드
	mBitmap = (HBITMAP)LoadImage(NULL, strFilePath.c_str(), IMAGE_BITMAP
		, 0, 0, LR_LOADFROMFILE); 
	assert(mBitmap);

	// bitmap과 연결할 DC가 있어야함
	mDC = CreateCompatibleDC(Core::GetInst()->GetMainDC());

	HBITMAP prev = (HBITMAP)SelectObject(mDC, mBitmap);
	DeleteObject(prev);
	
	// 이미지의 가로 세로 길이 받기
	// 특정 오브젝트의 정보 받기 위해서는 GetObject
	GetObject(mBitmap, sizeof(BITMAP), &mBitmapInfo);

	
}
