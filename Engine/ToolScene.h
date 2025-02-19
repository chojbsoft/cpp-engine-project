#pragma once
#include "Scene.h"
class ToolScene : public Scene
{
public:
	virtual void Enter() override;
	virtual void Exit() override;

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

};

