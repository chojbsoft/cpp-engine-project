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
	GetCurrentDirectory(255, _resourcePath);
	
	ToParentDir(2);
	wcscat_s(_resourcePath, 255, L"\\Resource");
}

void PathManager::ToParentDir(int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		int len = wcslen(_resourcePath);
	
		// 뒤에서부터 역슬래시(\\)가 나오는 곳을 찾고, 널문자로 교체해서 erase
		for (int j = len - 1; j >= 0; --j)
		{
			if (_resourcePath[j] == '\\')
			{
				_resourcePath[j] = '\0';
				break;
			}
		}
	}
}
