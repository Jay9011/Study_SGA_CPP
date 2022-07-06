#include "Framework.h"
#include "Mario.h"

Mario::Mario() :
	state(IDLE), speed(100.f), jumpSpeed(0), isRight(true), isJump(false)
{
	vector<Texture*> frames;

	// IDEL
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 1, 3));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 3));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 5, 3));

	actions.push_back(new Animation(frames));
	frames.clear();

	// MOVE
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 1, 3));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 3));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 3, 3));

	actions.push_back(new Animation(frames));
	frames.clear();

	// JUMP
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 0));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 3, 0));
	
	actions.push_back(new Animation(frames, END, 0.3f));
	frames.clear();

	actions[state]->Play();

	pos = { WIN_CENTER_X, WIN_CENTER_Y };
}

Mario::~Mario()
{
	for (Animation* action : actions)
	{
		delete action;
	}
}

void Mario::Update()
{
	Move();
	Jump();

	actions[state]->Update();
	UpdateWorld();
}

void Mario::Render()
{
	SetWorld();
	actions[state]->Render();
}

void Mario::Move()
{
	KEYBOARD->Move(*this, speed);
}

void Mario::Jump()
{
}
