#pragma once
#include "ObjectArray.h"

class Collider;

class Object
{
public:
	Object();
	virtual ~Object();

public:
	virtual void Update();
	virtual void UpdateLate() final;
	virtual void Render(HDC dc);

public:
	void SetPos(Vec2 pos);
	void SetScale(Vec2 scale);
	Vec2 GetPos();
	Vec2 GetScale();

public:
	void CreateCollider();

private:
	Collider* collider;

private:
	Vec2 pos;
	Vec2 scale;
};


template<class T, class... Args>
shared_ptr<T> NewObject(Args&&... args)
{
	// ó�� ������ ����
	// ���߿� allocator ������ �ű��
	const type_info& typeInfo = typeid(T);
	size_t classSize = sizeof(T);
	if (!GObjectArray.IsExist(typeInfo))
	{
		// allocate_shared�� �޸�Ǯ���� ���������� �����ϱ� ����, ���۷���ī��Ʈ ũ�� ���
		const int SharedPtrSize = sizeof(_Ref_count_obj_alloc3 <T, Allocator<T>>) - sizeof(T);

		// �޸�Ǯ ����
		GObjectArray.Create(typeInfo, SharedPtrSize + classSize);
	}

	// std::forward�� ������ ���� Ÿ�� ����
	return allocate_shared<T>(Allocator<T>(typeInfo), std::forward<Args>(args)...);
}