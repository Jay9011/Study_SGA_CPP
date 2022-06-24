#pragma once

#define MAX_KEY 256

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	void Update();

	bool  Down(DWORD key) { return keyMap[key] == DOWN;  };
	bool Press(DWORD key) { return keyMap[key] == PRESS; };
	bool    Up(DWORD key) { return keyMap[key] == UP;    };


private:
	enum KeyState
	{
		NONE,
		DOWN,
		UP,
		PRESS
	};

	byte keyOldState[MAX_KEY];
	byte keyState[MAX_KEY];
	byte keyMap[MAX_KEY];


};
