#include "Framework.h"
#include "Manager.h"

Manager* Manager::instance = nullptr;

Manager::Manager()
{
	keyboard = new Keyboard;
	textures = new TextureManager;
	time	 = new Time();
	effects  = new EffectManager;
}

Manager::~Manager()
{
	delete keyboard;
	delete textures;
	delete time;
	delete effects;

	Shader::Delete();
}

void Manager::Update()
{
	keyboard->Update();
	    time->Update();
     effects->Update();
}

void Manager::Render()
{
	effects->Render();
	   time->Render();
}

