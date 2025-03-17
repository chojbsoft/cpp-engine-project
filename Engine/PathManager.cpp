#include "pch.h"
#include "PathManager.h"
#include "Core.h"

PathManager::PathManager()
{

}

PathManager::~PathManager()
{

}

void PathManager::Init()
{
	GetCurrentDirectory(255, mResourcePath);
	
	ToParentDir(2);
	wcscat_s(mResourcePath, 255, L"\\Resource");
	SetWindowText(Core::GetInst()->GetMainHwnd(), mResourcePath);
}

void PathManager::ToParentDir(int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		int len = wcslen(mResourcePath);
	
		// �ڿ������� ��������(\\)�� ������ ���� ã��, �ι��ڷ� ��ü�ؼ� erase
		for (int j = len - 1; j >= 0; --j)
		{
			if (mResourcePath[j] == '\\')
			{
				mResourcePath[j] = '\0';
				break;
			}
		}
	}
}
