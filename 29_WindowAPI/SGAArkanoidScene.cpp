#include "Framework.h"
#include "SGAArkanoidScene.h"

SGAArkanoidScene::SGAArkanoidScene()
{
	player = new SGABar();
	  ball = new SGABall();
}

SGAArkanoidScene::~SGAArkanoidScene()
{
	delete player;
	delete ball;
}

void SGAArkanoidScene::Update()
{
	player->Update();
	  ball->Update();
}

void SGAArkanoidScene::Render(HDC hdc)
{
	player->Render(hdc);
	  ball->Render(hdc);
}
