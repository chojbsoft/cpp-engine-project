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
	void CheckGroup(GROUP_TYPE left, GROUP_TYPE right);
	void Reset();

private:
	void UpdateInternal(GROUP_TYPE left, GROUP_TYPE right);
	bool IsCollided(Collider* left, Collider* right);

private:
	int _check[(UINT)GROUP_TYPE::END];

	// 충돌체 간의 이전 프레임 충돌 상태
	// 맵의 키를 위해, 충돌체들은 모두 ID값을 가지고 있을 것
	// 쌍으로 필요하기 때문에, union으로 두 ID 이어서 키로 사용
	// 그럼 만약 오브젝트가 파괴됐을 때는 이 정보 어떻게 해제?
	unordered_map<ULONGLONG, bool> colInfo;


};

