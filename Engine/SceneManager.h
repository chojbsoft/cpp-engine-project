#pragma once

class Scene;

class SceneManager
{
	SINGLE(SceneManager);

public:
	Scene* GetCurScene() { return _curScene; }

public:
	void Init();
	void Update();
	void UpdateLate();
	void Render(HDC dc);

private:
	void ChangeScene(SCENE_TYPE next);
	friend class EventManager;

private:
	Scene* _scenes[(UINT)SCENE_TYPE::END];
	Scene* _curScene;

};

