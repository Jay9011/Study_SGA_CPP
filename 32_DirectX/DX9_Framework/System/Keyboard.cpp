#include "Framework.h"
#include "Keyboard.h"

Keyboard::Keyboard()
{
	// 구조체/배열 초기화 방법
	// 1.변수 선언시 = {}; , 2.ZeroMemory, 3.memset

	ZeroMemory(keyState,    sizeof(keyState));
	ZeroMemory(keyOldState, sizeof(keyOldState));
	ZeroMemory(keyMap,      sizeof(keyMap));

	//memset(keyState, 100, sizeof(keyState));
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update()
{
	memcpy(keyOldState, keyState, sizeof(keyState));

	ZeroMemory(keyState, sizeof(keyState));
	ZeroMemory(keyMap  , sizeof(keyMap));

	//   1,   0 : 키보드를 누르지 않은 상태
	// 129, 128 : 키보드를 누른 상태 
	GetKeyboardState(keyState);
	
	for (int i = 0; i < MAX_KEY; i++)
	{
		byte key = keyState[i] & 0x80;
		keyState[i] = key ? 1 : 0;

		byte old = keyOldState[i];
		byte cur = keyState[i];

		if (old == 0 && cur == 1)      //이전 0, 현재 1 : KeyDown
			keyMap[i] = DOWN;
		else if (old == 1 && cur == 0) //이전 1, 현재 0 : KeyUp
			keyMap[i] = UP;
		else if (old == 1 && cur == 1) //이전 1, 현재 1 : KeyPress
			keyMap[i] = PRESS;
		else
			keyMap[i] = NONE;

	}
}

void Keyboard::Move(Transform* transform, float speed)
{
	if (Press(VK_LEFT))
		transform->pos += Vector2(-1,  0) * speed * Time::Delta();
	if (Press(VK_RIGHT))			  
		transform->pos += Vector2(+1,  0) * speed * Time::Delta();
	if (Press(VK_UP))				  
		transform->pos += Vector2( 0, -1) * speed * Time::Delta();
	if (Press(VK_DOWN))				  
		transform->pos += Vector2( 0, +1) * speed * Time::Delta();
}

void Keyboard::MoveASDW(Transform* transform, float speed)
{
	if (Press('A'))
		transform->pos += Vector2(-1,  0) * speed * Time::Delta();
	if (Press('D'))			  
		transform->pos += Vector2(+1,  0) * speed * Time::Delta();
	if (Press('W'))				  
		transform->pos += Vector2( 0, -1) * speed * Time::Delta();
	if (Press('S'))				  
		transform->pos += Vector2( 0, +1) * speed * Time::Delta();
}

