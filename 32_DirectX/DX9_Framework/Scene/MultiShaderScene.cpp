#include "Framework.h"
#include "MultiShaderScene.h"

MultiShaderScene::MultiShaderScene()
{
	mario = new Mario;
	background = new Object(L"Textures/IDLE.jpg", Vector2(WIN_WIDTH * 2, WIN_HEIGHT * 2));
	camera = new Camera;
	camera->SetBackground(background);
	camera->SetTarget(mario);
}

MultiShaderScene::~MultiShaderScene()
{
	delete mario;
}

void MultiShaderScene::Update()
{
	background->Update();
	     mario->Update();
		camera->Update();
}

void MultiShaderScene::Render()
{
	background->Render();
	     mario->Render();
}

