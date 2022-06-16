#pragma once
class CameraScene : public Scene
{
public:
	CameraScene();
	~CameraScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Texture* bgTex;
	Object*  bg;

	Missile* missile;
};
