#include "Framework.h"
#include "XMLScene.h"

XMLScene::XMLScene()
{
	knight = new Knight();
}

XMLScene::~XMLScene()
{
	delete knight;
}

void XMLScene::Update()
{
	knight->Update();
}

void XMLScene::Render(HDC hdc)
{
	knight->Render();
}
