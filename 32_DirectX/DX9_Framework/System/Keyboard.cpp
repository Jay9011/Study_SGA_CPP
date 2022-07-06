#include "Framework.h"
#include "Keyboard.h"

Keyboard::Keyboard()
{
	/*
	* ����ü/�迭 �ʱ�ȭ ���
	* 1. ���� ����� = {};
	* 2. ZeroMemory()
	* 3. memset()
	*/
	ZeroMemory(keyState   , sizeof(keyState));
	ZeroMemory(keyOldState, sizeof(keyOldState));
	ZeroMemory(keyMap     , sizeof(keyMap));
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update()
{
	memcpy(keyOldState, keyState, sizeof(keyState));

	ZeroMemory(keyState, sizeof(keyState));
	ZeroMemory(keyMap  , sizeof(keyMap));

	/*
	*	��ȯ��
	*	  1,   0 : Ű���带 ������ ���� ����
	*	129, 128 : Ű���带 ���� ����
	*/
	GetKeyboardState(keyState);

	for (int i = 0; i < MAX_KEY; i++)
	{
		byte key = keyState[i] & 0x80;
		keyState[i] = key ? 1 : 0;

		byte old = keyOldState[i];
		byte cur = keyState[i];

		if (old == 0 && cur == 1)		// ���� 0, ���� 1 : KeyDown
			keyMap[i] = DOWN;
		else if (old == 1 && cur == 0)	// ���� 1, ���� 0 : KeyUP
			keyMap[i] = UP;
		else if (old == 1 && cur == 1)	// ���� 1, ���� 1 : KeyPress
			keyMap[i] = PRESS;
		else
			keyMap[i] = NONE;
	}
}

void Keyboard::Move(Transform& transform, float speed)
{
	if (Press(VK_LEFT))
		transform.pos += D3DXVECTOR2(-1,  0) * speed * Time::Delta();
	if (Press(VK_RIGHT))
		transform.pos += D3DXVECTOR2(+1,  0) * speed * Time::Delta();
	if (Press(VK_UP))
		transform.pos += D3DXVECTOR2(0, -1) * speed * Time::Delta();
	if (Press(VK_DOWN))
		transform.pos += D3DXVECTOR2(0, +1) * speed * Time::Delta();
}

void Keyboard::MoveASDW(Transform& transform, float speed)
{
	if (Press('A'))
		transform.pos += D3DXVECTOR2(-1, 0) * speed * Time::Delta();
	if (Press('D'))
		transform.pos += D3DXVECTOR2(+1, 0) * speed * Time::Delta();
	if (Press('W'))
		transform.pos += D3DXVECTOR2(0, -1) * speed * Time::Delta();
	if (Press('S'))
		transform.pos += D3DXVECTOR2(0, +1) * speed * Time::Delta();
}
