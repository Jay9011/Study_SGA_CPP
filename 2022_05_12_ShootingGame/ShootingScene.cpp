#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
	: time(0)
{
	Gdiplus::GdiplusStartup(&token, &input, nullptr);
	TextureManager::Create();
}

ShootingScene::~ShootingScene()
{
	TextureManager::Delete();
	Gdiplus::GdiplusShutdown(token);
}

void ShootingScene::Update()
{
}

void ShootingScene::Render(HDC hdc)
{
}
