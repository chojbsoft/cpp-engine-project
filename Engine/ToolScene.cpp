#include "pch.h"
#include "ToolScene.h"
#include "KeyManager.h"

void ToolScene::Enter()
{
}

void ToolScene::Exit()
{
}

void ToolScene::Update()
{
	Scene::Update();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}

void ToolScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}
