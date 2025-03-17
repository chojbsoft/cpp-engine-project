#include "pch.h"
#include "Scene.h"

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)OBJECT_TYPE::END; ++i)
	{
		for (size_t j = 0; j < objs[i].size(); ++j)
		{
			// �޸� ������ �ȵ����� KillPending ������ �͵鵵 ����
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
			// KillPending�̶� �浹ü ������Ʈ�� �ϱ�
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
	// �迭���� ������ ��� ������, back�� ���ڸ��� �ְ� pop_back
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


