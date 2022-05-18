#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
	: time(0)
{
	background	= TextureManager::Get()->AddTexture("BTS", L"Textures/BTS.bmp");
	bgRect   = new Rect(0, 0, WIN_WIDTH, WIN_HEIGHT);

	enemies = new EnemyManager(30);
	plane = new Plane();
}

TextureScene::~TextureScene()
{
	delete bgRect;

	delete plane;
	delete enemies;
}

void TextureScene::Update()
{
	enemies->Update();
	  plane->Update();
	  plane->Collision(enemies);
}

void TextureScene::Render(HDC hdc)
{
	background->Render(bgRect);
	   enemies->Render();
	     plane->Render();
}
