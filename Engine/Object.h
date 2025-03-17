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
	void RenderComponent(HDC dc);

public:
	void SetPos(Vec2 pos);
	void SetScale(Vec2 scale);
	Vec2 GetPos();
	Vec2 GetScale();
	Collider* GetCollider();

public:
	void CreateCollider(Vec2 offsetPos, Vec2 scale);

private:
	Collider* _collider = nullptr;

private:
	Vec2 _pos;
	Vec2 _scale;
};


template<class T, class... Args>
shared_ptr<T> NewObject(Args&&... args)
{
	// ó�� ������ ����
	// ���߿� allocator ������ �ű��
	const type_info& typeInfo = typeid(T);
	size_t classSize = sizeof(T);
	if (!_objectArray.IsExist(typeInfo))
	{
		// allocate_shared�� �޸�Ǯ���� ���������� �����ϱ� ����, ���۷���ī��Ʈ ũ�� ���
		const int SharedPtrSize = sizeof(_Ref_count_obj_alloc3 <T, Allocator<T>>) - sizeof(T);

		// �޸�Ǯ ����
		_objectArray.Create(typeInfo, SharedPtrSize + classSize);
	}

	// std::forward�� ������ ���� Ÿ�� ����
	return allocate_shared<T>(Allocator<T>(typeInfo), std::forward<Args>(args)...);
}