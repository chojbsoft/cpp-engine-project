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
	// 처음 생성일 때만
	// 나중에 allocator 안으로 옮길것
	const type_info& typeInfo = typeid(T);
	size_t classSize = sizeof(T);
	if (!_objectArray.IsExist(typeInfo))
	{
		// allocate_shared로 메모리풀에서 연속적으로 관리하기 위해, 레퍼런스카운트 크기 계산
		const int SharedPtrSize = sizeof(_Ref_count_obj_alloc3 <T, Allocator<T>>) - sizeof(T);

		// 메모리풀 생성
		_objectArray.Create(typeInfo, SharedPtrSize + classSize);
	}

	// std::forward로 인자의 참조 타입 유지
	return allocate_shared<T>(Allocator<T>(typeInfo), std::forward<Args>(args)...);
}