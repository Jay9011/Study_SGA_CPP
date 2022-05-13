#include "Framework.h"
#include "PlayerManager.h"

PlayerManager* PlayerManager::instance = nullptr;

PlayerManager::PlayerManager()
{
	player = new Player();

	OutputDebugString(L"PlayerManager ����\n");
}

PlayerManager::~PlayerManager()
{
	delete player;

	OutputDebugString(L"~PlayerManager �Ҹ�\n");
}

void PlayerManager::Update()
{
	player->Update();
}

void PlayerManager::Render(HDC hdc)
{
	player->Render(hdc);
}
