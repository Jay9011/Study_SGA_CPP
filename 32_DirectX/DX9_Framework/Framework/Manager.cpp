#include "Framework.h"
#include "Manager.h"

Manager* Manager::instance = nullptr;

Manager::Manager()
{
	device = new Device;
}

Manager::~Manager()
{
	delete device;
}