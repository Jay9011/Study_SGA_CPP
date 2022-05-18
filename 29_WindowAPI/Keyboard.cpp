#include "Framework.h"
#include "Keyboard.h"

Keyboard* Keyboard::instance = nullptr;

Keyboard::Keyboard()
{}

Keyboard::~Keyboard()
{}

void Keyboard::Create()
{
	if (instance == nullptr)
	{
		instance = new Keyboard;
	}
}

void Keyboard::Delete()
{
	if (instance != nullptr)
	{
		delete instance;
	}
}

Keyboard* Keyboard::Get()
{
	return instance;
}

/*
*	Key State
*	0001	-	이전에 누른적이 있고 (호출 시점에 안눌린 상태)
*	8000	-	(이전에 눌린 적 없고) 호출 시점에 눌린 상태
*	8001	-	이전에 눌린 적 있고 호출 시점에서도 눌린 상태
*/
bool Keyboard::Up(DWORD _key)
{
	if (GetAsyncKeyState(_key))
	{
		keyUp[_key] = true;
	}
	else
	{
		if (keyUp[_key])
		{
			keyUp[_key] = false;
			return true;
		}
	}

	return false;
}

bool Keyboard::Down(DWORD _key)
{
	if (GetAsyncKeyState(_key))
	{
		if (!keyDown[_key])
		{
			keyDown[_key] = true;
			return true;
		}
	}
	else
	{
		keyDown[_key] = false;
	}

	return false;
}

bool Keyboard::Press(DWORD _key)
{
	if (GetAsyncKeyState(_key))
	{
		return true;
	}
	return false;
}
