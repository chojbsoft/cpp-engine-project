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


private:
    // �ؽ�ó�� �ȼ������Ϳ� DC�� �̷���� ����
    HDC mDC;
    HBITMAP mBitmap;

private:
    BITMAP mBitmapInfo;

};

