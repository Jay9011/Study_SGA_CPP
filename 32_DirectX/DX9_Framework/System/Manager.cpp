#include "Framework.h"
#include "Manager.h"

Manager* Manager::instance = nullptr;

Manager::Manager()
{
	device   = new Device;
	keyboard = new Keyboard;
	textures = new TextureManager;
}

Manager::~Manager()
{
	delete textures;
	delete keyboard;
	delete device;
}

void Manager::Update()
{
	keyboard->Update();
}
