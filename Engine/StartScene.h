#pragma once
#include "Scene.h"

class StartScene : public Scene
{
	// �ѱ�
public:
	virtual void Enter();
	virtual void Exit();

	shared_ptr<Object> shared;
};

