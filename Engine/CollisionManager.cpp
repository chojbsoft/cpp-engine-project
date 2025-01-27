#include "pch.h"
#include "CollisionManager.h"

void CollisionManager::CheckGroup(GROUP_TYPE left, GROUP_TYPE right)
{
	// check[left] |= 1 << right;
	// 더 작은 숫자를 행으로 접근해야, 이차원 배열에서 반만 사용할 수 있음
	
}

void CollisionManager::Reset()
{
	memset(_check, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
}
