#include "Framework.h"
#include "PlayerManager.h"

PlayerManager* PlayerManager::instance = nullptr;

PlayerManager::PlayerManager()
{
	player = new Player();

	OutputDebugString(L"PlayerManager »ý¼º\n");
}

PlayerManager::~PlayerManager()
{
	delete player;

	OutputDebugString(L"~PlayerManager ¼Ò¸ê\n");
}

void PlayerManager::Update()
{
	player->Update();
}

void PlayerManager::Render(HDC hdc)
{
	player->Render(hdc);
}
