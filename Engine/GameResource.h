#pragma once
class GameResource
{
public:
	GameResource(){}
	virtual ~GameResource(){}

public:
	GameResource(wstring strKey, wstring strRelPath) 
		: _key(strKey), _relativePath(strRelPath) {}

private:
	wstring _key;
	wstring _relativePath; 

public:
	void SetKey(const wstring& strKey) { _key = strKey; }
	void SetRelativePath(const wstring& strPath) { _relativePath = strPath; }

	const wstring& GetKey() { return _key; }
	const wstring& GetRelativePath() { return _relativePath; }

};

