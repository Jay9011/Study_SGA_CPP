#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
	: time(0)
	, gameover(false)
{
	Gdiplus::GdiplusStartup(&token, &input, nullptr);
	TextureManager::Create();
	     UIManager::Create();
	 PlayerManager::Create();
	  EnemyManager::Create();
	 BulletManager::Create();
}

ShootingScene::~ShootingScene()
{
	 BulletManager::Delete();
	  EnemyManager::Delete();
	 PlayerManager::Delete();
	     UIManager::Delete();
	TextureManager::Delete();
	Gdiplus::GdiplusShutdown(token);
}

void ShootingScene::Update()
{
	if (gameover)
		return;

	if (PlayerManager::Get()->player->GetCurHp() < 0)
		gameover = true;
	
	    UIManager::Get()->Update();
	PlayerManager::Get()->Update();
	 EnemyManager::Get()->Update();
	BulletManager::Get()->Update();

}

void ShootingScene::Render(HDC hdc)
{
	    UIManager::Get()->Render(hdc);
	PlayerManager::Get()->Render(hdc);
	 EnemyManager::Get()->Render(hdc);
	BulletManager::Get()->Render(hdc);

	if (gameover)
	{
		wstring scoreText = L"Game Over !!!";
		TextOut(hdc, WIN_CENTER_X, WIN_CENTER_Y, scoreText.c_str(), scoreText.length());
	}
}
