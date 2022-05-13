#include "Framework.h"
#include "PlayerManager.h"

PlayerManager* PlayerManager::instance = nullptr;

PlayerManager::PlayerManager()
{
	player = new Player();
}

PlayerManager::~PlayerManager()
{
	delete player;
}

void PlayerManager::Update()
{
	player->Update();
}

void PlayerManager::Render(HDC hdc)
{
	player->Render(hdc);
}
