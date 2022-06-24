#pragma once
class Manager
{
/*
* Singleton
*/
private:
	Manager();
	~Manager();
public:
	static void     Create() { if (instance == nullptr) instance = new Manager; }
	static void     Delete() { delete instance; }
	static Manager* Get()    { return instance; }
private:
	static Manager* instance;

/*
*  Member
*/
public:
	Device*   GetDevice()   { return device; }
	Keyboard* GetKeyboard() { return keyboard; }

private:
	Device*   device;
	Keyboard* keyboard;

/*
*	Update
*/
public:
	void Update();
};
