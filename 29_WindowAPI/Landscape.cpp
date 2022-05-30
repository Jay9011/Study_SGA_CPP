#include "Framework.h"
#include "Landscape.h"

Landscape::Landscape()
	: bgSpeed(100)
{
	Texture* bgTexture = TextureManager::Get()->AddTexture("Background", L"Textures/background.bmp");

	for (int i = 0; i < BACKGROUND; i++)
	{
		backgrounds.push_back(new Object(bgTexture));

		backgrounds[i]->GetRect()->Pos() = 
		{ 
			bgTexture->GetFrameSize().x * 0.5 + bgTexture->GetFrameSize().x * i,
			bgTexture->GetFrameSize().y * 0.5
		};
	}
}

Landscape::~Landscape()
{
	for (Object*& background : backgrounds)
	{
		delete background;
	}
}

void Landscape::Update()
{
	for (Object*& background : backgrounds)
	{
		background->GetRect()->Pos() += V_LEFT * bgSpeed * Time::Delta();
		
		if (background->GetRect()->Right() < 0)
		{
			background->GetRect()->Pos().x += background->GetRect()->Size().x * BACKGROUND;
		}
	}
}

void Landscape::Render()
{
	for (Object*& background : backgrounds)
	{
		background->Render();
	}
}
