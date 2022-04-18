#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	//scene = new PaintScene();
	scene = new CollisionScene();
}

MainGame::~MainGame()
{
	delete scene;
}

void MainGame::Update()
{
	scene->Update();
}

void MainGame::Render(HDC hdc)
{
	scene->Render(hdc);
}
