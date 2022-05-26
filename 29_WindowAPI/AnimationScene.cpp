#include "Framework.h"
#include "AnimationScene.h"

AnimationScene::AnimationScene()
{
	landscape = new Landscape;
	mario = new Mario(landscape);
}

AnimationScene::~AnimationScene()
{
	delete mario;
	delete landscape;
}

void AnimationScene::Update()
{
	mario->Update();
	landscape->Update();
}

void AnimationScene::Render(HDC hdc)
{
	landscape->Render();
	mario->Render();
}
