#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
	: sivaFrame({ 0, 0 })
	, sivaSpeed(10)
	, time(0)
{
	TextureManager::Create();

	background	= TextureManager::Get()->AddTexture("BTS", L"Textures/BTS.bmp");
	siva		= TextureManager::Get()->AddTexture("siva", L"Textures/siva_run.bmp", 8, 2);
	bgRect   = new Rect(0, 0, WIN_WIDTH, WIN_HEIGHT);
	sivaRect = new Rect({ WIN_CENTER_X, WIN_CENTER_Y }, { 100, 100 });

	enemies = new EnemyManager(30);
}

TextureScene::~TextureScene()
{
	delete sivaRect;
	delete bgRect;

	delete enemies;

	TextureManager::Delete();
}

void TextureScene::Update()
{
	time++;
	if (time > 10)
	{
		time = 0;
		++sivaFrame.x %= siva->GetMaxFrame().x;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		sivaFrame.y = 1;
		sivaRect->Pos() += V_LEFT * sivaSpeed;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		sivaFrame.y = 0;
		sivaRect->Pos() += V_RIGHT * sivaSpeed;

	}

	enemies->Update();
}

void TextureScene::Render(HDC hdc)
{
	background->Render(bgRect);
	      siva->Render(sivaRect, sivaFrame);
	   enemies->Render();
}
