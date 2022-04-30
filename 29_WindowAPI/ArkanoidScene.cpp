#include "Framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	arkanoidUI = new AKUI();
	arkanoidBallManager = new AKBallManager(10);
	
	arkanoidPlayer = new AKPlayer(*arkanoidUI, *arkanoidBallManager);
	arkanoidCollisionManager = new AKCollisionManager(
		arkanoidUI,
		arkanoidPlayer,
		arkanoidBallManager
	);
}

ArkanoidScene::~ArkanoidScene()
{
	delete arkanoidCollisionManager;
	delete arkanoidBallManager;
	delete arkanoidPlayer;
	delete arkanoidUI;
}

void ArkanoidScene::Update()
{
	arkanoidCollisionManager->Update();
	arkanoidUI->Update();
	arkanoidBallManager->Update();
	arkanoidPlayer->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	arkanoidUI->Render(hdc);
	arkanoidBallManager->Render(hdc);
	arkanoidPlayer->Render(hdc);
	arkanoidCollisionManager->Render(hdc);
}