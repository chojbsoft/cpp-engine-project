#include "pch.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "Scene.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::Init()
{
}

void CollisionManager::Update()
{
	// 활성화되어 있는 충돌 채널 확인
	for (int i = 0; i < (int)GROUP_TYPE::END; ++i)
	{
		// col은 항상 row보다 같거나 크게해서, 효율적으로
		for (int j = i; j < (int)GROUP_TYPE::END; ++j)
		{
			if (_check[i] & (1 << j))
			{
				UpdateInternal((GROUP_TYPE)i, (GROUP_TYPE)j);
			}
		}
	}
}

void CollisionManager::CheckGroup(GROUP_TYPE left, GROUP_TYPE right)
{
	// 더 작은 숫자를 행으로 접근하기
	// 그래야 일관성 있게, 이차원 배열에서 반만 사용할 수 있음
	UINT row = (UINT)left;
	UINT col = (UINT)right;
	if (row > col)
	{
		swap(row, col);
	}

	// 토글
	if (_check[row] & (1 << col))
	{
		// 비트 끄기
		_check[row] &= ~(1 << col);
	}
	else
	{
		// 비트 켜기
		_check[row] |= 1 << col;
	}

}

void CollisionManager::Reset()
{
	memset(_check, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
}

void CollisionManager::UpdateInternal(GROUP_TYPE left, GROUP_TYPE right)
{
	Scene* currScene = SceneManager::GetInst()->GetCurScene();

	// 레퍼런스로 받기
	const vector<shared_ptr<Object>>& leftObjs = currScene->GetGroupObject(left);
	const vector<shared_ptr<Object>>& rightObjs = currScene->GetGroupObject(right);

	for (int i = 0; i < leftObjs.size(); ++i)
	{
		Collider* leftCollider = leftObjs[i]->GetCollider();
		if (!leftCollider)
		{
			continue;
		}

		for (int j = 0; j < (int)GROUP_TYPE::END; ++j)
		{
			Collider* rightCollider = rightObjs[i]->GetCollider();
			if (!rightObjs[j]->GetCollider())
			{
				continue;
			}

			// 서로 타입이 같을 때, 같은 오브젝트일 수 있음
			if (leftCollider == rightCollider)
			{
				continue;
			}

			if (IsCollided(leftCollider, rightCollider))
			{

			}

		}
	}

}

bool CollisionManager::IsCollided(Collider* left, Collider* right)
{

}
