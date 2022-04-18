#pragma once

class MainGame
{
public:
	MainGame();
	~MainGame();

	void Update();
	void Render(HDC hdc);

private:
	Scene* scene;
};
