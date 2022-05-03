#include "Framework.h"
#include "SGAArkanoidScene.h"

SGAArkanoidScene::SGAArkanoidScene()
{
	player = new SGABar;
	  ball = new SGABall;
	 brick = new SGABrick;

	  ball->SetBarRect(player->GetRect());
}

SGAArkanoidScene::~SGAArkanoidScene()
{
	delete player;
	delete ball;
	delete brick;
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
	 brick->Render(hdc);
}
