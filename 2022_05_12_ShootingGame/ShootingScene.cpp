#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
	: time(0)
{
	Gdiplus::GdiplusStartup(&token, &input, nullptr);
	TextureManager::Create();
	PlayerManager::Create();
	BulletManager::Create();
}

ShootingScene::~ShootingScene()
{
	BulletManager::Delete();
	PlayerManager::Delete();
	TextureManager::Delete();
	Gdiplus::GdiplusShutdown(token);
}

void ShootingScene::Update()
{
	PlayerManager::Get()->Update();
	BulletManager::Get()->Update();
}

void ShootingScene::Render(HDC hdc)
{
	PlayerManager::Get()->Render(hdc);
	BulletManager::Get()->Render(hdc);
}
