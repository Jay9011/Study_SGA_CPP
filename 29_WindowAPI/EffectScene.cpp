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

	// Sound
	//System_Create(&system);	// 시스템 받아오기
	//system->init(1, FMOD_INIT_NORMAL, nullptr); // 시스템 구축
	//system->createSound("Sounds/Bom-Ming-Bom-Ming.wav", FMOD_DEFAULT, nullptr, &sound); // 사운드 읽기

	SoundManager::Get()->AddSound("Bom-Ming-Bom-Ming", "Sounds/Bom-Ming-Bom-Ming.wav", false);

	SoundManager::Get()->AddSound("BGM1", "Sounds/Mega Man 2 [RockMan 2 - Dr. Wily no Nazo] [1].mp3", true);
	SoundManager::Get()->Play("BGM1", .1f);
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

	//if (KEY_DOWN(VK_F1))
	//{
	//	/*system->playSound(sound, nullptr, false, &channel);
	//	channel->setVolume(.5f);*/
	//	SoundManager::Get()->Play("Bom-Ming-Bom-Ming", .3f);
	//}


	//effect->Update();
	knight->Update();
}

void EffectScene::Render(HDC hdc)
{
	mountain->Render();
	  knight->Render();
	//effect->Render();
}
