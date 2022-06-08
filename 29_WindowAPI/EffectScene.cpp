#include "Framework.h"
#include "EffectScene.h"

EffectScene::EffectScene()
{
	Texture* texture = TextureManager::Get()->AddTexture("Effect4", L"Textures/effect4.png", 4, 4);

	//effect = new CEffect(texture);
	EffectManager::Get()->AddEffect("Effect4", texture, 30);
}

EffectScene::~EffectScene()
{
	//delete effect;
}

void EffectScene::Update()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		//effect->Play(mousePos);
		EffectManager::Get()->Play("Effect4", mousePos);
	}

	//effect->Update();
}

void EffectScene::Render(HDC hdc)
{
	//effect->Render();
}
