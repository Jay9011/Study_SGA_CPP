#include "Framework.h"
#include "EffectScene.h"

EffectScene::EffectScene()
{
	Texture* texture = TextureManager::Get()->AddTexture("Effect4", L"Textures/effect4.png", 4, 4);

	//effect = new CEffect(texture);
	EffectManager::Get()->AddEffect("Effect4", texture, 30);

	Texture* bitmap = TextureManager::Get()->AddBitMap("Mountain", L"Textures/mountain_large.bmp", WIN_WIDTH, WIN_HEIGHT);
	mountain = new Object(bitmap);
	mountain->GetRect()->Pos() = { WIN_CENTER_X, WIN_CENTER_Y };

	knight = new Knight();
}

EffectScene::~EffectScene()
{
	//delete effect;
	delete mountain;
	delete knight;
}

void EffectScene::Update()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		//effect->Play(mousePos);
		EffectManager::Get()->Play("Effect4", mousePos);
	}

	//effect->Update();
	knight->Update();
}

void EffectScene::Render(HDC hdc)
{
	mountain->Render();
	  knight->Render();
	//effect->Render();
}
