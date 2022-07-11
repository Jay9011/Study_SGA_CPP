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
	Keyboard*       GetKeyboard() { return keyboard; }
	TextureManager* GetTextures() { return textures; }
	Time*           GetTime()     { return time; }

private:
	Keyboard*       keyboard;
	TextureManager* textures;
	Time*           time;

/*
*	Update & Render
*/
public:
	void Update();
	void Render();
};
