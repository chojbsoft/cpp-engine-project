#pragma once

class Object;

class Collider
{
public:
	Collider(Object* owner, Vec2 offsetPos, Vec2 scale);
	Collider(const Collider& other);

	// ���� �����ڴ� ���Ƶα�
	const Collider& operator=(const Collider& other) = delete;

public:
	void UpdateLate();
	void Render(HDC dc);

public:
	UINT GetID() { return _ID; };
	Vec2 GetFinalPos() { return _finalPos; };
	Vec2 GetScale() { return _scale; };

public:
	// �浹 ���� ����
	void OnCollision(Collider* other);

	void OnCollisionEnter(Collider* other);

	void OnCollisionEnd(Collider* other);

private:
	// ����ٴϱ� ���� �����ڸ� �˾ƾ���
	Object* _owner;
	Vec2 _offsetPos;
	Vec2 _scale;

	// UpdateLate���� ���
	Vec2 _finalPos;

private:
	UINT _ID;
	
	// ������ ID�� �ο��ϱ� ���� static ����
	// ������
	static inline UINT _nextID;

	int _isColliding = false;
	
};

