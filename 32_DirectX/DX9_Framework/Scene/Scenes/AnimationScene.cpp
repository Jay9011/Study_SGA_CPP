#include "Framework.h"
#include "AnimationScene.h"

AnimationScene::AnimationScene()
{
	mario = new Mario;
	knight = new Knight;
	
	knight->AddEnemy(mario->GetCollider());
}

AnimationScene::~AnimationScene()
{
	delete knight;
	delete mario;
}

void AnimationScene::Update()
{
	mario->Update();
	knight->Update();
}

void AnimationScene::Render()
{
	mario->Render();
	knight->Render();
}
