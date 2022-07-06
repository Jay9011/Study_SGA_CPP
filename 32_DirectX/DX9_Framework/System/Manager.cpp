#include "Framework.h"
#include "Manager.h"

Manager* Manager::instance = nullptr;

Manager::Manager()
{
	device   = new Device;
	keyboard = new Keyboard;
	textures = new TextureManager;
	time     = new Time(device->GetDevice());
}

Manager::~Manager()
{
	delete time;
	delete textures;
	delete keyboard;
	delete device;
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
