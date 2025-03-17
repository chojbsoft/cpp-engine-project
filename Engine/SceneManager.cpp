#include "pch.h"
#include "SceneManager.h"
#include "StartScene.h"

void SceneManager::Init()
{
	// Scene ����
	scenes[(UINT)SCENE_TYPE::START] = new StartScene();
	scenes[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");

	// ���� �� ����
	curScene = scenes[(UINT)SCENE_TYPE::START];
	curScene->Enter();
}

void SceneManager::Update()
{
	curScene->Update();
}

void SceneManager::Render(HDC _dc)
{
	curScene->Render(_dc);
}

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (scenes[i])
		{
			delete scenes[i];
			scenes[i] = nullptr;
		}
	}
}
