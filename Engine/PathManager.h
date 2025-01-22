#pragma once
class PathManager
{
	SINGLE(PathManager)

public:
	void Init();
	const wchar_t* GetResourcePath() { return _resourcePath; }

private:
	void ToParentDir(int cnt);

private:
	// 윈도우의 경로는 255자로 제한되어 있기 때문에, 여기서도 제한
	wchar_t _resourcePath[255];
};

