#pragma once
class GameResource
{
private:
	wstring mStrKey;
	wstring mStrRelativePath;

public:
	void SetKey(const wstring& strKey) { mStrKey = strKey; }
	void SetRelativePath(const wstring& strPath) { mStrRelativePath = strPath; }

	const wstring& GetKey() { return mStrKey; }
	const wstring& GetRelativePath() { return mStrRelativePath; }

};

