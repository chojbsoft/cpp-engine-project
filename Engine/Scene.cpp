#include "pch.h"
#include "Scene.h"

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < objs[i].size(); ++j)
		{
			// 메모리 해제는 안됐지만 KillPending 상태인 것들도 대응
			if (!objs[i][j]->IsDead())
			{
				objs[i][j]->Update();
			}
		}
	}
}

void Scene::UpdateLate()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < objs[i].size(); ++j)
		{
			// KillPending이라도 충돌체 업데이트는 하기
			objs[i][j]->UpdateLate();
		}
	}
}

void Scene::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < objs[i].size(); ++j)
		{
			if (!objs[i][j]->IsDead())
			{
				objs[i][j]->Render(_dc);
			}
		}
	}
}

Scene::Scene()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		objs[i] = vector<shared_ptr<Object>>();
	}
}

Scene::~Scene()
{
}

void Scene::AddObject(shared_ptr<Object> obj, OBJECT_TYPE type)
{
	objs[(UINT)type].push_back(obj);
}

void Scene::DeleteObject(shared_ptr<Object> obj, OBJECT_TYPE type)
{
	// 배열에서 순서가 상관 없으니, back을 그자리에 넣고 pop_back
	auto it = find(objs[(UINT)type].begin(), objs[(UINT)type].end(), obj);
	*it = objs[(UINT)type].back();
	objs[(UINT)type].pop_back();
}

void Scene::DeleteAll()
{
	for (size_t i = 0; i < (size_t)OBJECT_TYPE::END; ++i)
	{
		DeleteGroup((OBJECT_TYPE)i);
	}
}

void Scene::DeleteGroup(OBJECT_TYPE type)
{
	objs[(UINT)type].clear();
}


