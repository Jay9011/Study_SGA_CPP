#pragma once
class Camera
{
private:
	Camera();
	~Camera();

	static void Create();
	static void Delete();

	static Camera* Get();

	void Update();

private:
	static Camera* instance;

	Vector2 pos;
	double speed;


};
