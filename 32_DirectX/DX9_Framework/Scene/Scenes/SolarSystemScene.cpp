#include "Framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	sun = new Planet(0xFFAA3300, 0xFFAAAA00, 100.f, .01f, .01f, 12);
	sun->pos = { WIN_CENTER_X, WIN_CENTER_Y };

	earth = new Planet(0xFF2233AA, 0xFF00AA33, 50.f, -.01f, -.01f, 12);
	earth->pos = { 150, 150 };
	earth->SetParent(sun);

	moon = new Planet(0xFFCCDDCC, 0xAAAAAA, 10.f, -.02f, -.02f, 12);
	moon->pos = { 50, 50 };
	moon->SetParent(earth);
}

SolarSystemScene::~SolarSystemScene()
{
	delete moon;
	delete earth;
	delete sun;
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
