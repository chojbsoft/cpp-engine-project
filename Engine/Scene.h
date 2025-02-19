#pragma once
#include "Object.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	virtual void Render(HDC _dc);
	virtual void Update();
	virtual void UpdateLate();

public:
	void AddObject(shared_ptr<Object> obj, OBJECT_TYPE type);
	void DeleteObject(shared_ptr<Object> obj, OBJECT_TYPE type);
	void DeleteAll();
	void DeleteGroup(OBJECT_TYPE type);

public:
	const wstring& GetName() { return strName; }
	void SetName(const wstring& strName) { this->strName = strName; }
	const vector<shared_ptr<Object>>& GetGroupObject(OBJECT_TYPE type) { return objs[(UINT)type]; }

private:
	vector<shared_ptr<Object>> objs[(UINT)OBJECT_TYPE::END];
	wstring strName;
};

