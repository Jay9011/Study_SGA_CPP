#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	//scene = new VertexScene;
	//scene = new WVPScene;
	//scene = new SolarSystemScene;
	//scene = new TextureScene;
	scene = new CollisionScene;
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
