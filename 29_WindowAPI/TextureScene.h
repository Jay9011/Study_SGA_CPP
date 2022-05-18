#pragma once

class TextureScene : public Scene
{
public:
	TextureScene();
	~TextureScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Texture*	background;
	Rect*		bgRect;

	EnemyManager* enemies;
	Plane*		  plane;

	int time;
};
