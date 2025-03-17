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

void CollisionManager::CheckGroup(OBJECT_TYPE left, OBJECT_TYPE right)
{
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
	memset(_check, 0, sizeof(UINT) * (UINT)OBJECT_TYPE::END);
}

void CollisionManager::Update()
{
	// Ȱ��ȭ�Ǿ� �ִ� �浹 ä�� Ȯ��
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		// col�� �׻� row���� ���ų� ũ���ؼ�, ȿ��������
		for (int j = i; j < (int)OBJECT_TYPE::END; ++j)
		{
			if (_check[i] & (1 << j))
			{
				UpdateInternal((OBJECT_TYPE)i, (OBJECT_TYPE)j);
			}
		}
	}
}

void CollisionManager::UpdateInternal(OBJECT_TYPE left, OBJECT_TYPE right)
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

		for (int j = 0; j < rightObjs.size(); ++j)
		{
			Collider* rightCollider = rightObjs[j]->GetCollider();
			if (!rightCollider)
			{
				continue;
			}

			// ���� Ÿ���� ���� ��, ���� ������Ʈ�� �� ����
			if (leftCollider == rightCollider)
			{
				continue;
			}

			// ���� �������� �浹 ������ ����
			COLLIDER_ID ID;
			ID.left = leftCollider->GetID();
			ID.right = rightCollider->GetID();
			unordered_map<ULONGLONG, bool>::iterator iter = colInfo.find(ID.ID);

			// ���ٸ� ���
			if (iter == colInfo.end())
			{
				colInfo.insert({ ID.ID, false });
				iter = colInfo.find(ID.ID);
			}

			// ���� ������ �浹
			if (IsCollided(leftCollider, rightCollider))
			{
				// �������� �浹
				if (iter->second)
				{
					leftCollider->OnCollision(rightCollider);
					rightCollider->OnCollision(leftCollider);
				}
				// ���Ӱ� �浹
				else
				{
					leftCollider->OnCollisionBegin(rightCollider);
					rightCollider->OnCollisionBegin(leftCollider);
					iter->second = true;
				}
			}
			// ���� ������ �浹 ����
			else
			{
				// ���� ������ �浹 �߾���
				if (iter->second)
				{
					leftCollider->OnCollisionEnd(rightCollider);
					rightCollider->OnCollisionEnd(leftCollider);
					iter->second = false;
				}
			}
		}
	}
}

bool CollisionManager::IsCollided(Collider* left, Collider* right)
{
	Vec2 leftPos = left->GetFinalPos();
	Vec2 leftScale = left->GetScale();

	Vec2 rightPos = right->GetFinalPos();
	Vec2 rightScale = right->GetScale();

	// x �Ÿ��� x ���� ũ�⸦ ���� ������ ���ų� �۴ٸ� 
	if (abs(rightPos._x - leftPos._x) < (rightScale._x + leftScale._x) / 2.f
		&& abs(rightPos._y - leftPos._y) < (rightScale._y + leftScale._y) / 2.f)
	{
		return true;
	}

	return false;
}
