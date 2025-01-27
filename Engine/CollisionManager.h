#pragma once



class CollisionManager
{
	SINGLE(CollisionManager)

private:
	int _check[(UINT)GROUP_TYPE::END];

public:
	void Init();
	void Update();
	void CheckGroup(GROUP_TYPE left, GROUP_TYPE right);
	void Reset();

};

