#include "pch.h"
#include "Scene.h"
#include "Object.h"

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

void Scene::Render(HDC dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < objs[i].size(); ++j)
		{
			objs[i][j]->Render(dc);
		}
	}
}

Scene::Scene()
{

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
