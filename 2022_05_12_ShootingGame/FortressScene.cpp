#include "Framework.h"
#include "FortressScene.h"

FortressScene::FortressScene()
{
	tank = new Tank();
}

FortressScene::~FortressScene()
{
	delete tank;
}

void FortressScene::Update()
{
	tank->Update();
}

void FortressScene::Render(HDC hdc)
{
	tank->Render(hdc);
}
