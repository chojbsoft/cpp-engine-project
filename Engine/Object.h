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
	virtual void OnCollision(Collider* other);
	virtual void OnCollisionBegin(Collider* other);
	virtual void OnCollisionEnd(Collider* other);

public:
	void SetPos(Vec2 pos);
	void SetScale(Vec2 scale);
	Vec2 GetPos();
	Vec2 GetScale();
	Collider* GetCollider();

public:
	bool IsDead() { return _isAlive; }

public:
	void CreateCollider(Vec2 offsetPos, Vec2 scale);

private:
	// EventManager�� ó���� �� �ְ�
	void SetDead() { _isAlive = false; }
	friend class EventManager;

protected:
	Vec2 _pos;
	Vec2 _scale;

private:
	bool _isAlive = true;

private:
	Collider* _collider = nullptr;

};


template<class T, class... Args>
shared_ptr<T> NewObject(Args&&... args)
{
	const type_info& typeInfo = typeid(T);
	size_t classSize = sizeof(T);
	if (!_objectArray.IsExist(typeInfo))
	{
		const int SharedPtrSize = sizeof(_Ref_count_obj_alloc3 <T, Allocator<T>>) - sizeof(T);
		_objectArray.Create(typeInfo, SharedPtrSize + classSize);
	}

	return allocate_shared<T>(Allocator<T>(typeInfo), std::forward<Args>(args)...);
}