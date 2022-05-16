#pragma once

class TextureScene : public Scene
{
public:
	TextureScene();
	~TextureScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Texture*	background;
	Rect*		bgRect;

	Texture*	siva;
	Rect*		sivaRect;
	POINT		sivaFrame;
	double		sivaSpeed;

	Enemy*		enemy;

	int time;
};
