#pragma once
class PathManager
{
	SINGLE(PathManager)

public:
	void Init();
	const wchar_t* GetResourcePath() { return mResourcePath; }

private:
	void ToParentDir(int cnt);

private:
	// �������� ��δ� 255�ڷ� ���ѵǾ� �ֱ� ������, ���⼭�� ����
	wchar_t mResourcePath[255];
};

