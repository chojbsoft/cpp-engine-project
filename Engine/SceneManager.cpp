#include "pch.h"
#include "SceneManager.h"
#include "StartScene.h"
#include "ToolScene.h"

void SceneManager::Init()
{
	// Scene 생성
	_scenes[(UINT)SCENE_TYPE::START] = new StartScene();
	_scenes[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	_scenes[(UINT)SCENE_TYPE::TOOL] = new ToolScene();
	_scenes[(UINT)SCENE_TYPE::TOOL]->SetName(L"Tool Scene");

	// 현재 씬 지정
	_curScene = _scenes[(UINT)SCENE_TYPE::START];
	_curScene->Enter();
}

void SceneManager::Update()
{
	_curScene->Update();
}

void SceneManager::UpdateLate()
{
	_curScene->UpdateLate();
}

void SceneManager::Render(HDC _dc)
{
	_curScene->Render(_dc);
}

void SceneManager::ChangeScene(SCENE_TYPE next)
{
	_curScene->Exit();
	_curScene = _scenes[(UINT)next];
	_curScene->Enter();
}

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (_scenes[i])
		{
			delete _scenes[i];
			_scenes[i] = nullptr;
		}
	}
}
