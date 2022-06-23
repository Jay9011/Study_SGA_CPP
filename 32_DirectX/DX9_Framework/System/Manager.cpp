#include "Framework.h"
#include "Manager.h"

Manager* Manager::instance = nullptr;

Manager::Manager()
{
	device   = new Device;
	keyboard = new Keyboard;
}

Manager::~Manager()
{
	delete device;
	delete keyboard;
}