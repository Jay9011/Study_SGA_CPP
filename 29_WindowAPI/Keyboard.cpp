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
*	0001	-	������ �������� �ְ� (ȣ�� ������ �ȴ��� ����)
*	8000	-	(������ ���� �� ����) ȣ�� ������ ���� ����
*	8001	-	������ ���� �� �ְ� ȣ�� ���������� ���� ����
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
