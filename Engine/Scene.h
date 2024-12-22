#pragma once
#include <string>

class Object;

class Scene
{
private:
	// 다형성 있게 자식들을 담아두기 위해
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

	// 모든 자식 씬들이 같은 이름의 다른 멤버 함수를 가지고 있으니
	// 순수 가상함수로 선언
	virtual void Enter() = 0;
	virtual void Exit() = 0;

	// 모든 자식 씬들이 똑같은 함수를 사용함
	void Update();
	void Render(HDC _dc);


public:
	Scene();
	virtual ~Scene();
};

