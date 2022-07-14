#pragma once

class Manager
{
private:
	Manager();
	~Manager();

public:
	static void Create() 
	{ 
		if(instance == nullptr) 
		   instance = new Manager; 
	}
	static void Delete() { delete instance; }

	static Manager* Get() { return instance; }

	Keyboard*       GetKeyboard() { return keyboard; }
	TextureManager* GetTextures() { return textures; }
	Time*			GetTime()     { return time;     }
	EffectManager*  GetEffects()  { return effects;  }

	void Update();
	void Render();

private:
	static Manager* instance;

	Keyboard*       keyboard;
	TextureManager* textures;
	Time*			time;
	EffectManager*  effects;
};
