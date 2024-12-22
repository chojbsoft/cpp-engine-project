#pragma once
#include <string>

class Object;

class Scene
{
private:
	// ������ �ְ� �ڽĵ��� ��Ƶα� ����
	vector<Object*> objs[(UINT)GROUP_TYPE::END];
	wstring strName;

public:
	void AddObject(Object* obj, GROUP_TYPE type)
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

	// ��� �ڽ� ������ ���� �̸��� �ٸ� ��� �Լ��� ������ ������
	// ���� �����Լ��� ����
	virtual void Enter() = 0;
	virtual void Exit() = 0;

	// ��� �ڽ� ������ �Ȱ��� �Լ��� �����
	void Update();
	void Render(HDC _dc);


public:
	Scene();
	virtual ~Scene();
};

