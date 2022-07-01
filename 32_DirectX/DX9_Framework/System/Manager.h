#pragma once
class Manager
{
/*
* Singleton
*/
private:
	Manager();
	virtual ~Manager();
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
	Device*         GetDevice()   { return device; }
	Keyboard*       GetKeyboard() { return keyboard; }
	TextureManager* GetTextures() { return textures; }

private:
	Device*         device;
	Keyboard*       keyboard;
	TextureManager* textures;

/*
*	Update
*/
public:
	void Update();
};
