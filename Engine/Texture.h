#pragma once
#include "GameResource.h"
class Texture :
    public GameResource
{
private:
    // 텍스처는 픽셀데이터와 DC로 이루어져 있음
    HDC mDC;
    HBITMAP mBitmap;

public:
    void Load(const wstring& strFilePath);

};

