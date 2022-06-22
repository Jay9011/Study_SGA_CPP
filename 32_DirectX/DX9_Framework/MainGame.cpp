#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	scene = new VertexScene;
}

MainGame::~MainGame()
{
	delete scene;
}

void MainGame::Update()
{
	scene->Update();
}

void MainGame::Render()
{
	scene->Render();
}
