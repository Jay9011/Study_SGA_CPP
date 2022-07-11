#include "Framework.h"
#include "Manager.h"

Manager* Manager::instance = nullptr;

Manager::Manager()
{
	keyboard = new Keyboard;
	textures = new TextureManager;
	time     = new Time();
}

Manager::~Manager()
{
	delete time;
	delete textures;
	delete keyboard;
}

void Manager::Update()
{
	keyboard->Update();
	time->Update();
}

void Manager::Render()
{
	time->Render();
}
