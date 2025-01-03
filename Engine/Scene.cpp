#include "pch.h"
#include "Scene.h"

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < objs[i].size(); ++j)
		{
			objs[i][j]->Update();
		}
	}
}

void Scene::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < objs[i].size(); ++j)
		{
			objs[i][j]->Render(_dc);
		}
	}
}

Scene::Scene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		objs[i] = vector<Object*>();
	}
}

Scene::~Scene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < objs[i].size(); ++j)
		{
			delete objs[i][j];
		}
	}
}


