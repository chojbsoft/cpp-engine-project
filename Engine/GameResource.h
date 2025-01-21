#pragma once
class GameResource
{
public:
	GameResource(){}
	virtual ~GameResource(){}

public:
	GameResource(wstring strKey, wstring strRelPath) 
		: mStrKey(strKey), mStrRelativePath(strRelPath) {}

private:
	wstring mStrKey; // 이름
	wstring mStrRelativePath; // 상대경로

public:
	void SetKey(const wstring& strKey) { mStrKey = strKey; }
	void SetRelativePath(const wstring& strPath) { mStrRelativePath = strPath; }

	const wstring& GetKey() { return mStrKey; }
	const wstring& GetRelativePath() { return mStrRelativePath; }

};

