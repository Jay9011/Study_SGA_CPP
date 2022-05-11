#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
	: sivaFrame({ 0, 0 })
	, sivaSpeed(10)
	, time(0)
{
	Gdiplus::GdiplusStartup(&token, &input, nullptr);

	background  = new Texture(L"Textures/BTS.bmp");
	bgRect      = new Rect(0, 0, WIN_WIDTH, WIN_HEIGHT);

	siva     = new Texture(L"Textures/siva_run.bmp", 8, 2);
	sivaRect = new Rect({ WIN_CENTER_X, WIN_CENTER_Y }, { 100, 100 });
}

TextureScene::~TextureScene()
{
	delete background;
	delete bgRect;
	delete siva;
	delete sivaRect;

	Gdiplus::GdiplusShutdown(token);
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
}

void TextureScene::Render(HDC hdc)
{
	background->Render(bgRect);
	      siva->Render(sivaRect, sivaFrame);
}
