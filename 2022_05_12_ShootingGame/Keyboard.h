#pragma once

#define	MAX_KEY_INPUT	255

#define	KEY_UP(p)		Keyboard::Get()->Up(p)
#define	KEY_DOWN(p)		Keyboard::Get()->Down(p)
#define	KEY_PRESS(p)	Keyboard::Get()->Press(p)

class Keyboard
{
public:
	static void Create();
	static void Delete();

	static Keyboard* Get();

	bool Up(DWORD _key);
	bool Down(DWORD _key);
	bool Press(DWORD _key);

private:
	Keyboard();
	~Keyboard();

	static Keyboard* instance;

	bitset<MAX_KEY_INPUT> keyUp;
	bitset<MAX_KEY_INPUT> keyDown;

};
