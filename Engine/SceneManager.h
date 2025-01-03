#pragma once

class Scene;

class SceneManager
{
	SINGLE(SceneManager);

private:
	Scene* scenes[(UINT)SCENE_TYPE::END];
	Scene* curScene;

public:
	Scene* GetCurScene() { return curScene; }

public:
	void Init();
	void Update();
	void Render(HDC dc);
};

