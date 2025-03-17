#pragma once
#include "Collider.h"

union COLLIDER_ID
{
	struct
	{
		UINT left;
		UINT right;
	};
	ULONGLONG ID;
};


class CollisionManager
{
	SINGLE(CollisionManager)

public:
	void Init();
	void Update();
	void CheckGroup(OBJECT_TYPE left, OBJECT_TYPE right);
	void Reset();

private:
	void UpdateInternal(OBJECT_TYPE left, OBJECT_TYPE right);
	bool IsCollided(Collider* left, Collider* right);

private:
	int _check[(UINT)OBJECT_TYPE::END];

	// �浹ü ���� ���� ������ �浹 ����
	// ���� Ű�� ����, �浹ü���� ��� ID���� ������ ���� ��
	// ������ �ʿ��ϱ� ������, union���� �� ID �̾ Ű�� ���
	// �׷� ���� ������Ʈ�� �ı����� ���� �� ���� ��� ����?
	unordered_map<ULONGLONG, bool> colInfo;


};

