#pragma once
#include "Object.h"

class Scene
{
public:
	Scene();

	virtual ~Scene();

private:
	vector<shared_ptr<Object>> objs[(UINT)GROUP_TYPE::END];
	wstring strName;

public:
	void AddObject(shared_ptr<Object> obj, GROUP_TYPE type)
	{
		objs[(UINT)type].push_back(obj);
	}

public:
	void SetName(const wstring& strName)
	{
		this->strName = strName;
	}

	const wstring& GetName()
	{
		return strName;

	}

	const vector<shared_ptr<Object>>& GetGroupObject(GROUP_TYPE type)
	{
		return objs[(UINT)type];
	}

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void Render(HDC _dc);
	void Update();
	void UpdateLate();


};

