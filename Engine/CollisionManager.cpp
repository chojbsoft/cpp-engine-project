#include "pch.h"
#include "CollisionManager.h"

void CollisionManager::CheckGroup(GROUP_TYPE left, GROUP_TYPE right)
{
	// check[left] |= 1 << right;
	// �� ���� ���ڸ� ������ �����ؾ�, ������ �迭���� �ݸ� ����� �� ����
	
}

void CollisionManager::Reset()
{
	memset(_check, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
}
