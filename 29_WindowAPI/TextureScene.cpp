#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
	: time(0)
{
	background	= TextureManager::Get()->AddTexture("Space", L"Textures/Space.jpg");
	bgRect   = new Rect(0, 0, background->GetFrameSize().x, background->GetFrameSize().y);

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
	// update �� ó��
	enemies->GetPlayer(plane);

	/*
		���� update
	*/
	  plane->Update();
	enemies->Update();

	// update ���� ó��
	  plane->Collision(enemies);
}

void TextureScene::Render(HDC hdc)
{
	background->Render(bgRect);
	   enemies->Render();
	     plane->Render();
}
