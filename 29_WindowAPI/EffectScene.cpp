#include "Framework.h"
#include "EffectScene.h"

EffectScene::EffectScene()
{
}

EffectScene::~EffectScene()
{
	Release();
}

void EffectScene::Update()
{
	//effect->Update();
	knight->Update();

	if (KEY_DOWN(VK_LBUTTON))
	{
		//effect->Play(mousePos);
		EffectManager::Get()->Play("Effect4", mousePos);
	}

	if (KEY_DOWN(VK_RBUTTON))
	{
		SceneManager::Get()->ChangeScene("XMLScene");
	}

	//if (KEY_DOWN(VK_F1))
	//{
	//	/*system->playSound(sound, nullptr, false, &channel);
	//	channel->setVolume(.5f);*/
	//	SoundManager::Get()->Play("Bom-Ming-Bom-Ming", .3f);
	//}
}

void EffectScene::Render(HDC hdc)
{
	mountain->Render();
	  knight->Render();
	//effect->Render();
}

void EffectScene::Initialize()
{
	Texture* texture = TextureManager::Get()->AddTexture("Effect4", L"Textures/effect4.png", 4, 4);

	//effect = new CEffect(texture);
	EffectManager::Get()->AddEffect("Effect4", texture, 30);

	TextureManager::Get()->DeleteTexture("Mountain");
	Texture* bitmap = TextureManager::Get()->AddBitMap("Mountain", L"Textures/mountain_large.bmp", WIN_WIDTH, WIN_HEIGHT);
	mountain = new Object(bitmap);
	mountain->GetRect()->Pos() = { WIN_CENTER_X, WIN_CENTER_Y };

	knight = new Knight();

	// Sound
	//System_Create(&system);	// �ý��� �޾ƿ���
	//system->init(1, FMOD_INIT_NORMAL, nullptr); // �ý��� ����
	//system->createSound("Sounds/Bom-Ming-Bom-Ming.wav", FMOD_DEFAULT, nullptr, &sound); // ���� �б�

	SoundManager::Get()->AddSound("Bom-Ming-Bom-Ming", "Sounds/Bom-Ming-Bom-Ming.wav", false);

	SoundManager::Get()->AddSound("BGM1", "Sounds/Mega Man 2 [RockMan 2 - Dr. Wily no Nazo] [1].mp3", true);
	SoundManager::Get()->Play("BGM1", .1f);
}

void EffectScene::Release()
{
	//delete effect;
	if (mountain != nullptr)
		delete mountain;
	mountain = nullptr;

	if (knight != nullptr)
		delete knight;
	knight = nullptr;
}
