#include "Framework.h"
#include "AnimationScene.h"

AnimationScene::AnimationScene()
{
	texture = TextureManager::Get()->AddTexture("Siva", L"Textures/siva_run.bmp", 8, 2);

	animation = new Animation(texture, .5);
	//animation->SetDefault(true);
	//animation->SetPart(0, 1, true);
	
	UINT arr[] = { 0, 15, 2, 8 };
	animation->SetArray(arr, sizeof(arr), true, true);
	animation->Play();

	rect = new Rect({ WIN_CENTER_X, WIN_CENTER_Y }, texture->GetFrameSize());
}

AnimationScene::~AnimationScene()
{
	delete rect;
	delete animation;
}

void AnimationScene::Update()
{
	animation->Update();
}

void AnimationScene::Render(HDC hdc)
{
	texture->Render(rect, animation->GetFrame());
}
