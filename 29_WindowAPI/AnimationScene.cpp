#include "Framework.h"
#include "AnimationScene.h"

AnimationScene::AnimationScene()
{
	landscape = new Landscape;
	mario     = new Mario(landscape);
	blocks    = new BlockManager(TextureManager::Get()->AddTexture("Block", L"Textures/BrickBlock_50.png", Gdiplus::Color::White), 10);
}

AnimationScene::~AnimationScene()
{
	delete mario;
	delete landscape;
	delete blocks;
}

void AnimationScene::Update()
{
	landscape->Update();
	mario->Update();
	mario->CollisionBlock(blocks);
	blocks->Update();
}

void AnimationScene::Render(HDC hdc)
{
	landscape->Render();
	mario->Render();
	blocks->Render();
}
