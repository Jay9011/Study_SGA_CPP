#include "Framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	sun = new Planet(0xFFFFFF00, 100, 0.01f, 0.01f);
	sun->pos = { WIN_CENTER_X, WIN_CENTER_Y };

	earth = new Planet(0xFF0000FF, 50, -0.04f, -0.04f);
	earth->pos = { 150, 150 };
	earth->SetParent(sun);

	moon = new Planet(0xFFFFFFFF, 10, 0.08f, 0.08f);
	moon->pos = { 50, 50 };
	moon->SetParent(earth);
}

SolarSystemScene::~SolarSystemScene()
{
	delete sun;
	delete earth;
	delete moon;
}

void SolarSystemScene::Update()
{
	  sun->Update();
	earth->Update();
	 moon->Update();
}

void SolarSystemScene::Render()
{
	  sun->Render();
	earth->Render();
	 moon->Render();
}

