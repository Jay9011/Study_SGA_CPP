#pragma once

#define MAX_KEY 256

class Transform;

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	void Update();

	bool  Down(DWORD key) { return keyMap[key] == DOWN; }
	bool    Up(DWORD key) { return keyMap[key] == UP; }
	bool Press(DWORD key) { return keyMap[key] == PRESS; }

	void Move(Transform* transform, float speed);
	void MoveASDW(Transform* transform, float speed);

private:
	enum KeyState
	{
		NONE,
		DOWN,
		UP,
		PRESS
	};

	byte keyState[MAX_KEY];
	byte keyOldState[MAX_KEY];
	byte keyMap[MAX_KEY];
};
