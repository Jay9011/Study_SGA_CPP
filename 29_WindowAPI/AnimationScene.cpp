#include "Framework.h"
#include "AnimationScene.h"

AnimationScene::AnimationScene()
{
	landscape = new Landscape;
	mario = new Mario(landscape);
	
	block = new Block(TextureManager::Get()->AddTexture("Block", L"Textures/BrickBlock.png", Gdiplus::Color::White));
}

AnimationScene::~AnimationScene()
{
	delete mario;
	delete landscape;
	
	delete block;
}

void AnimationScene::Update()
{
	landscape->Update();
	mario->Update();

	block->Update();
}

void AnimationScene::Render(HDC hdc)
{
	landscape->Render();
	mario->Render();

	block->Render();
}
