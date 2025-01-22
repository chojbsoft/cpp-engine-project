#pragma once

class Scene;

class SceneManager
{
	SINGLE(SceneManager);

private:
	Scene* _scenes[(UINT)SCENE_TYPE::END];
	Scene* _curScene;

public:
	Scene* GetCurScene() { return _curScene; }

public:
	void Init();
	void Update();
	void UpdateLate();
	void Render(HDC dc);
};

