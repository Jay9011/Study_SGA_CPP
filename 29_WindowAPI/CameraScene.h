#pragma once
class CameraScene : public Scene
{
public:
	CameraScene();
	~CameraScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Texture* bgTex;
	Object*  bg;

	Missile* missile;
};
