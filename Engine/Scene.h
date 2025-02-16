#pragma once
#include "Object.h"

class Scene
{
public:
	Scene();

	virtual ~Scene();

private:
	vector<shared_ptr<Object>> objs[(UINT)OBJECT_TYPE::END];
	wstring strName;

public:
	void AddObject(shared_ptr<Object> obj, OBJECT_TYPE type)
	{
		objs[(UINT)type].push_back(obj);
	}
	void DeleteObject(shared_ptr<Object> obj, OBJECT_TYPE type)
	{
		// 배열에서 순서가 상관 없으니, back을 그자리에 넣고 pop_back
		auto it = find(objs[(UINT)type].begin(), objs[(UINT)type].end(), obj);
		*it = objs[(UINT)type].back();
		objs[(UINT)type].pop_back();
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

	const vector<shared_ptr<Object>>& GetGroupObject(OBJECT_TYPE type)
	{
		return objs[(UINT)type];
	}

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void Render(HDC _dc);
	void Update();
	void UpdateLate();


};

