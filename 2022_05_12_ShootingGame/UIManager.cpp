#include "Framework.h"
#include "UIManager.h"

UIManager* UIManager::instance = nullptr;

UIManager::UIManager()
	: bgFrame({0 ,0})
	, bgSpeed(60)
	, cloudsSpeed(120)
{
	bgImg	  = TextureManager::Get()->AddTexture("background", L"Textures/background.png");
	cloudsImg = TextureManager::Get()->AddTexture("clouds", L"Textures/clouds.png");
	
	for (int i = 0; i < bgCnt; i++)
	{
		bgImgRect[i] = new Rect({ WIN_CENTER_X, (272.0 * (i + 1.0)) - 272.0 }, { 256, 272 });
	}

	for (int i = 0; i < cloudCnt; i++)
	{
		cloudsImgRect[i] = new Rect({ WIN_CENTER_X, (309 * (i + 1.0)) - 309 }, { 256, 103 });
	}
}

UIManager::~UIManager()
{
	for (int i = 0; i < bgCnt; i++)
	{
		delete bgImgRect[i];
	}

	for (int i = 0; i < cloudCnt; i++)
	{
		delete cloudsImgRect[i];
	}
}

void UIManager::Update()
{
	for (int i = 0; i < bgCnt; i++)
	{
		bgImgRect[i]->Pos() += Vector2(0, bgSpeed * Time::Delta());

		// Over Screen
		if (bgImgRect[i]->Top() >= (double)WIN_HEIGHT + 20)
		{
			int minY = bgImgRect[i]->Top();

			for (int j = 0; j < bgCnt; j++)
			{
				if (minY > bgImgRect[j]->Top())
					minY = bgImgRect[j]->Top();
			}

			bgImgRect[i]->Pos().y = minY - (272.0 * 0.5);
			bgImgRect[i]->Pos().y += minY - bgImgRect[i]->Bottom() + 1;
		}
	}
	
	for (int i = 0; i < cloudCnt; i++)
	{
		cloudsImgRect[i]->Pos() += Vector2(0, cloudsSpeed * Time::Delta());

		// Over Screen
		if (cloudsImgRect[i]->Top() >= (double)WIN_HEIGHT + 20)
		{
			int minY = cloudsImgRect[i]->Top();

			for (int j = 0; j < cloudCnt; j++)
			{
				if (minY > cloudsImgRect[j]->Top())
					minY = cloudsImgRect[j]->Top();
			}

			cloudsImgRect[i]->Pos().y = minY - (309.0 / (rand() % 3 + 1));
		}
	}
}

void UIManager::Render(HDC hdc)
{
	for (int i = 0; i < bgCnt; i++)
	{
		bgImg->Render(bgImgRect[i]);
	}

	for (int i = 0; i < cloudCnt; i++)
	{
		cloudsImg->Render(cloudsImgRect[i]);
	}
}
