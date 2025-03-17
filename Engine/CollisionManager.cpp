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
	// Ȱ��ȭ�Ǿ� �ִ� �浹 ä�� Ȯ��
	for (int i = 0; i < (int)GROUP_TYPE::END; ++i)
	{
		// col�� �׻� row���� ���ų� ũ���ؼ�, ȿ��������
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
	// �� ���� ���ڸ� ������ �����ϱ�
	// �׷��� �ϰ��� �ְ�, ������ �迭���� �ݸ� ����� �� ����
	UINT row = (UINT)left;
	UINT col = (UINT)right;
	if (row > col)
	{
		swap(row, col);
	}

	// ���
	if (_check[row] & (1 << col))
	{
		// ��Ʈ ����
		_check[row] &= ~(1 << col);
	}
	else
	{
		// ��Ʈ �ѱ�
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

	// ���۷����� �ޱ�
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

			// ���� Ÿ���� ���� ��, ���� ������Ʈ�� �� ����
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
