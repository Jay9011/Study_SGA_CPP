#include "Framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	sun = new Planet(0xFFAA3300, 0xFFAAAA00, 100.f, .01f, .01f, 12);
	sun->pos = { WIN_CENTER_X, WIN_CENTER_Y };
}

SolarSystemScene::~SolarSystemScene()
{
	delete sun;
}

void SolarSystemScene::Update()
{
	sun->Update();
}

void SolarSystemScene::Render()
{
	sun->Render();
}
