#include "Framework.h"
#include "XMLScene.h"

XMLScene::XMLScene()
{
	knight = new Knight();

	Texture* up   = TextureManager::Get()->AddTexture("Up",   L"textures/btn-med-up.png");
	Texture* down = TextureManager::Get()->AddTexture("Down", L"textures/btn-med-down.png");
	Texture* over = TextureManager::Get()->AddTexture("Over", L"textures/btn-med-over.png");

	button = new Button(up, down, over, { WIN_CENTER_X, WIN_HEIGHT * 0.9 });
	button->SetEvent(bind(&XMLScene::ClickEvent, this));
}

XMLScene::~XMLScene()
{
	delete knight;
	delete button;
}

void XMLScene::Update()
{
	knight->Update();
	button->Update();
}

void XMLScene::Render(HDC hdc)
{
	knight->Render();
	button->Render();
}

void XMLScene::ClickEvent()
{
	knight->PlayAction();
}
