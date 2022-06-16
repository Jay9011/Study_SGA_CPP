#pragma once

class Object;

class Camera
{
private:
	Camera();
	~Camera();

public:
	static void Create();
	static void Delete();

	static Camera* Get();

	void Update();

	Vector2& Pos() { return pos; }

	const Object& GetTarget()         const { return *target; }
	void          SetTarget(Object* target) { this->target = target; }

private:
	static Camera* instance;

	Vector2 pos;
	double speed;

	Object* target;
	Vector2 offset;
};
