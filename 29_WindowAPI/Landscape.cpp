#include "Framework.h"
#include "Landscape.h"

Landscape::Landscape()
	: bgSpeed(100)
	, landSpeed(100)
{
	CreateBackground();
	CreateLand();
}

Landscape::~Landscape()
{
	for (Object*& background : backgrounds)
	{
		delete background;
	}
	for (Object*& land : lands)
	{
		delete land;
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

	//for (Object*& land : lands)
	//{
	//	land->GetRect()->Pos() += V_LEFT * landSpeed * Time::Delta();

	//	if (land->GetRect()->Right() < 0)
	//	{
	//		land->GetRect()->Pos().x += land->GetRect()->Size().x * LAND;
	//	}
	//}

	for (int i = 0; i < LAND; i++)
	{
		lands[i]->GetRect()->Pos() += V_LEFT * landSpeed * Time::Delta();

		if (lands[i]->GetRect()->Right() < 0)
		{
			int prev = (i + LAND - 1) % LAND;

			lands[i]->GetRect()->Pos().x = lands[prev]->GetRect()->Right() + lands[i]->GetRect()->Size().x * 0.5;

			double interval = Math::Random(100., 200.);
			if (Math::Random(0., 1.) < .2)
				lands[i]->GetRect()->Pos().x += interval;
		}
		
	}
}

void Landscape::Render()
{
	for (Object*& background : backgrounds)
	{
		background->Render();
	}
	for (Object*& land : lands)
	{
		land->Render();
	}
}

void Landscape::CreateBackground()
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

void Landscape::CreateLand()
{
	Texture* landTexture = TextureManager::Get()->AddTexture("Land", L"Textures/mario_tile1.png");
	
	for (int i = 0; i < LAND; i++)
	{
		lands.push_back(new Object(landTexture));
	
		int prev = (i + lands.size() - 1) % lands.size();

		lands[i]->GetRect()->Pos().y = WIN_HEIGHT - landTexture->GetFrameSize().y * 0.5;
		lands[i]->GetRect()->Pos().x = lands[prev]->GetRect()->Right() + lands[i]->GetRect()->Size().x * 0.5;

		double interval = Math::Random(100., 200.);
		if (Math::Random(0., 1.) < .2)
			lands[i]->GetRect()->Pos().x += interval;
	}
}
