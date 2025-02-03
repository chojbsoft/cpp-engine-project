#pragma once

class Object;

class Collider
{
public:
	Collider(Object* owner, Vec2 offsetPos, Vec2 scale);
	Collider(const Collider& other);

	// 대입 연산자는 막아두기
	const Collider& operator=(const Collider& other) = delete;

public:
	void UpdateLate();
	void Render(HDC dc);

public:
	UINT GetID() { return _ID; };
	Vec2 GetFinalPos() { return _finalPos; };
	Vec2 GetScale() { return _scale; };

public:
	// 충돌 중인 상태
	void OnCollision(Collider* other);

	void OnCollisionEnter(Collider* other);

	void OnCollisionEnd(Collider* other);

private:
	// 따라다니기 위해 소유자를 알아야함
	Object* _owner;
	Vec2 _offsetPos;
	Vec2 _scale;

	// UpdateLate에서 계산
	Vec2 _finalPos;

private:
	UINT _ID;
	
	// 고유한 ID를 부여하기 위한 static 변수
	// 생성자
	static inline UINT _nextID;

	int _isColliding = false;
	
};

