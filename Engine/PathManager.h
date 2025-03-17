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
	// �������� ��δ� 255�ڷ� ���ѵǾ� �ֱ� ������, ���⼭�� ����
	wchar_t _resourcePath[255];
};

