#pragma once
#include "GameResource.h"
class Texture :
    public GameResource
{
private:
    // �ؽ�ó�� �ȼ������Ϳ� DC�� �̷���� ����
    HDC mDC;
    HBITMAP mBitmap;

public:
    void Load(const wstring& strFilePath);

};

