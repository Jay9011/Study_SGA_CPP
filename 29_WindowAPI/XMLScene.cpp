#include "Framework.h"
#include "XMLScene.h"

XMLScene::XMLScene()
{
}

XMLScene::~XMLScene()
{
	Release();
}

void XMLScene::Update()
{
	//knight->Update();
	button->Update();

	if (isIncrease)
	{
		++alpha;

		if (alpha >= 255)
			isIncrease = false;
	}
	else
	{
		--alpha;
		if (alpha <= 0)
			isIncrease = true;
	}
}

void XMLScene::Render(HDC hdc)
{
	//knight->Render();
	texture->AlphaRender(rect, alpha);
	button->Render();
}

void XMLScene::Initialize()
{
	//knight = new Knight();

	Texture* up = TextureManager::Get()->AddTexture("Up", L"textures/btn-med-up.png");
	Texture* down = TextureManager::Get()->AddTexture("Down", L"textures/btn-med-down.png");
	Texture* over = TextureManager::Get()->AddTexture("Over", L"textures/btn-med-over.png");

	button = new Button(up, down, over, { WIN_CENTER_X, WIN_HEIGHT * 0.9 });
	button->SetEvent(bind(&XMLScene::ClickEvent, this));

	texture = TextureManager::Get()->AddBitMap("Mountain", L"Textures/mountain_large.bmp", WIN_WIDTH, WIN_HEIGHT);
	rect    = new Rect({ WIN_CENTER_X, WIN_CENTER_Y }, { WIN_WIDTH, WIN_HEIGHT });
}

void XMLScene::Release()
{
	//delete knight;
	if(button != nullptr)
		delete button;

	button = nullptr;

	if (rect != nullptr)
		delete rect;
	
	rect = nullptr;
}

void XMLScene::ClickEvent()
{
	//knight->PlayAction();
	SceneManager::Get()->ChangeScene("EffectScene");
}
