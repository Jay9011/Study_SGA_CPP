#include "Framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	arkanoidUI = new AKUI();
	arkanoidPlayer = new AKPlayer(*arkanoidUI);
}

ArkanoidScene::~ArkanoidScene()
{
	delete arkanoidPlayer;
	delete arkanoidUI;
}

void ArkanoidScene::Update()
{
}

void ArkanoidScene::Render(HDC hdc)
{
	arkanoidUI->Render(hdc);
	arkanoidPlayer->Render(hdc);
}
