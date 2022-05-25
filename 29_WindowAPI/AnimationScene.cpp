#include "Framework.h"
#include "AnimationScene.h"

AnimationScene::AnimationScene()
{
	//texture = TextureManager::Get()->AddTexture("Siva", L"Textures/siva_run.bmp", 8, 2);

	//animation = new Animation(texture, .3);
	////animation->SetDefault(true);
	////animation->SetPart(0, 1, true);
	//
	//vector<UINT> arr = { 2, 3, 4, 5, 6, 7 };
	//animation->SetVector(arr, true, false);
	//animation->Play();

	//rect = new Rect({ WIN_CENTER_X, WIN_CENTER_Y }, texture->GetFrameSize());

	mario = new Mario();
}

AnimationScene::~AnimationScene()
{
	/*delete rect;
	delete animation;*/
	
	delete mario;
}

void AnimationScene::Update()
{
	//animation->Update();
	mario->Update();
}

void AnimationScene::Render(HDC hdc)
{
	//texture->Render(rect, animation->GetFrame());
	mario->Render();
}
