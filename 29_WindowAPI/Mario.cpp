#include "Framework.h"
#include "Mario.h"

Mario::Mario()
	: speed(100)
	, state(IDLE_R)
{
	texture = TextureManager::Get()->AddTexture("Mario", L"Textures/mario_all.png", 8, 4);

	rect = new Rect({ WIN_CENTER_X, WIN_HEIGHT * 0.8 }, texture->GetFrameSize());

	AddAction();

	curAction = actions[state];
	curAction->Play();
}

Mario::~Mario()
{
	delete rect;

	for (Animation* action : actions)
	{
		if (nullptr != action)
			delete action;
	}
	actions.clear();
}

void Mario::Update()
{
	Move();
	curAction->Update();
}

void Mario::Render()
{
	texture->Render(rect, curAction->GetFrame());
}

void Mario::Move()
{
	if (KEY_PRESS(VK_LEFT))
	{
		rect->Pos() += V_LEFT * speed * Time::Delta();
		SetAction(RUN_L);
	}
	
	if (KEY_PRESS(VK_RIGHT))
	{
		rect->Pos() += V_RIGHT * speed * Time::Delta();
		SetAction(RUN_R);
	}
}

void Mario::SetAction(State state)
{
	if (this->state == state)
		return;

	this->state = state;
	curAction = actions[state];
	curAction->Play();
}

void Mario::AddAction()
{
	// IDLE_L
	actions.push_back(new Animation(texture));
	actions[IDLE_L]->SetVector({ 28, 23 }, true);
	// IDLE_R
	actions.push_back(new Animation(texture));
	actions[IDLE_R]->SetVector({ 24, 19 }, true);
	// RUN_L
	actions.push_back(new Animation(texture));
	actions[RUN_L]->SetPart(13, 15, true);
	// RUN_R
	actions.push_back(new Animation(texture));
	actions[RUN_R]->SetPart(9, 11, true);
}
