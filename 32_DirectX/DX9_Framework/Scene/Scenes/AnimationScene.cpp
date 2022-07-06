#include "Framework.h"
#include "AnimationScene.h"

AnimationScene::AnimationScene()
{
	mario = new Mario;
}

AnimationScene::~AnimationScene()
{
	delete mario;
}

void AnimationScene::Update()
{
	mario->Update();
}

void AnimationScene::Render()
{
	mario->Render();
}
