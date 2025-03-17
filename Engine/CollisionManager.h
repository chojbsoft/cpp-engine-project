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

	// �浹ü ���� ���� ������ �浹 ����
	// ���� Ű�� ����, �浹ü���� ��� ID���� ������ ���� ��

};

