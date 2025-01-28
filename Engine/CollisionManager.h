#pragma once



class CollisionManager
{
	SINGLE(CollisionManager)

public:
	void Init();
	void Update();
	void CheckGroup(GROUP_TYPE left, GROUP_TYPE right);
	void Reset();

private:
	void UpdateInternal(GROUP_TYPE left, GROUP_TYPE right);
	bool IsCollided(Collider* left, Collider* right);

private:
	int _check[(UINT)GROUP_TYPE::END];

	// 충돌체 간의 이전 프레임 충돌 상태
	// 맵의 키를 위해, 충돌체들은 모두 ID값을 가지고 있을 것

};

