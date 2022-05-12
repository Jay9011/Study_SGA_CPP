#include "Framework.h"
#include "SGAArkanoidScene.h"

SGAArkanoidScene::SGAArkanoidScene()
{
	  player = new SGABar;
	    ball = new SGABall;
	   //brick = new SGABrick;
	bManager = new SGABrickManager;

	  ball->SetBarRect(player->GetRect());
	  //ball->SetBrick(brick);
	  ball->SetBrickManager(bManager);
}

SGAArkanoidScene::~SGAArkanoidScene()
{
	delete player;
	delete ball;
	//delete brick;
	delete bManager;
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
	 //brick->Render(hdc);
	bManager->Render(hdc);
}
