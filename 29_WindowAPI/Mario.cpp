#include "Framework.h"
#include "Mario.h"

Mario::Mario()
	: Mario(nullptr)
{}

Mario::Mario(Landscape* landscape)
	: moveSpeed(500)
	, state(IDLE_R)
	, isJump(false)
	, jumpSpeed(0)
	, gravity(980)
	, jumpCount(0)
{
	this->landscape = landscape;

	texture = TextureManager::Get()->AddTexture("Mario", L"Textures/mario_all.png", 8, 4);
	rect = new Rect({ WIN_CENTER_X, landscape->GetLands()[0]->GetRect()->Top() - (texture->GetFrameSize().y / 2.) }, texture->GetFrameSize());

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
	Jump();
	Attack();

	curAction->Update();
	
}

void Mario::Render()
{
	texture->Render(rect, curAction->GetFrame());
	Debug();
}


void Mario::Move()
{
	if (KEY_PRESS(VK_LEFT))
	{
		rect->Pos() += V_LEFT * moveSpeed * Time::Delta();
		if (!isJump && !isSpin)
			SetAction(RUN_L);
	}
	if (KEY_PRESS(VK_RIGHT))
	{
		rect->Pos() += V_RIGHT * moveSpeed * Time::Delta();
		if (!isJump && !isSpin)
			SetAction(RUN_R);
	}

	if (KEY_UP(VK_LEFT))
	{
		SetAction(IDLE_L);
	}
	if (KEY_UP(VK_RIGHT))
	{
		SetAction(IDLE_R);
	}
}

void Mario::SetAction(int state)
{
	if (this->state == (State)state)
		return;

	this->state = (State)state;
	curAction = actions[state];
	curAction->Play();
}

void Mario::Attack()
{
	if (KEY_DOWN(VK_LCONTROL))
	{
		if (state % 2)
		{
			SetAction(ATK_R);
		}
		else
		{
			SetAction(ATK_L);
		}
	}
}

void Mario::Jump()
{
	if (KEY_DOWN(VK_SPACE) && jumpCount <= 1)
	{
		jumpSpeed = 500;
		isJump = true;
		++jumpCount;

		if (state % 2)
		{
			SetAction(JUMP_R);
		}
		else
		{
			SetAction(JUMP_L);
		}
	}

	jumpSpeed -= gravity * Time::Delta();
	rect->Pos().y -= jumpSpeed * Time::Delta();

	// 땅에 닿았을 때
	if (CollisionLand())
	{
		jumpSpeed = 0;

		if (!isJump)
			return;

		isJump = false;
		jumpCount = 0;

		//rect->Pos().y = WIN_HEIGHT - (rect->Size().y * 0.5);
		//SetIdle();
		
		if (state % 2)
			SetAction(SPIN_R);
		else
			SetAction(SPIN_L);

		isSpin = true;
	}
}

void Mario::SetIdle()
{
	if (state % 2)
	{
		SetAction(IDLE_R);
	}
	else
	{
		SetAction(IDLE_L);
	}
}

bool Mario::CollisionLand()
{
	for (Object* land : landscape->GetLands())
	{
		if (Collision::Collision(this->rect, land->GetRect()))
		{
			rect->Pos().y = land->GetRect()->Top() - rect->Size().y * 0.5;
			return true;
		}
	}

	return false;
}

bool Mario::CollisionBlock(BlockManager* blocks)
{
	for (Block* block : blocks->GetBlocks())
	{
		Rect cRect;

		if (block->IsActive() && Collision::Collision(&cRect, this->rect, block->GetRect()))
		{
			if (cRect.Size().x > cRect.Size().y) // 상하 충돌
			{
				if (rect->Pos().y > cRect.Pos().y)	// 아래에서 충돌
				{
					block->IsActive() = false;
					rect->Pos().y += cRect.Size().y;
					jumpSpeed = 0;	// 위로 올라가지 않고 중력을 받아야 한다.
				}
				else                                // 위에서 충돌
				{
					rect->Pos().y -= cRect.Size().y;
				}
			}
			else                                 // 좌우 충돌
			{
				if (rect->Pos().x > cRect.Pos().x)	// 오른쪽에서 충돌
				{
					rect->Pos().x += cRect.Size().x;
				}
				else                                // 왼쪽에서 충돌
				{
					rect->Pos().x -= cRect.Size().x;
				}
			}
		}
	}

	return false;
}

void Mario::Debug()
{
	wstring str;

	str = L"JumpSpeed: " + to_wstring(jumpSpeed);
	TextOut(backDC, 0, 60, str.c_str(), str.size());
}


void Mario::AddAction()
{
	// IDLE_L
	actions.push_back(new Animation(texture));
	actions[IDLE_L]->SetVector({ 28, 13 }, true);
	actions[IDLE_L]->SetUpdateTime(.5);
	// IDLE_R
	actions.push_back(new Animation(texture));
	actions[IDLE_R]->SetVector({ 24, 9 }, true);
	actions[IDLE_R]->SetUpdateTime(.5);
	// RUN_L
	actions.push_back(new Animation(texture));
	actions[RUN_L]->SetPart(13, 15, true);
	// RUN_R
	actions.push_back(new Animation(texture));
	actions[RUN_R]->SetPart(9, 11, true);
	// JUMP_L
	actions.push_back(new Animation(texture));
	actions[JUMP_L]->SetVector({ 4, 5, 6, 7 });
	//actions[JUMP_L]->SetNextEvent(bind(&Mario::SetAction, this, SPIN_L));
	// JUMP_R
	actions.push_back(new Animation(texture));
	actions[JUMP_R]->SetVector({ 0, 1, 2, 3 });
	//actions[JUMP_R]->SetNextEvent(bind(&Mario::SetAction, this, SPIN_R));
	// ATK_L
	actions.push_back(new Animation(texture));
	actions[ATK_L]->SetPart(28, 30);
	//actions[ATK_L]->SetEndEvent(bind(&Mario::SetIdle, this));
	actions[ATK_L]->SetNextEvent(bind(&Mario::SetAction, this, JUMP_L));
	// ATK_R
	actions.push_back(new Animation(texture));
	actions[ATK_R]->SetPart(24, 26);
	//actions[ATK_R]->SetEndEvent(bind(&Mario::SetIdle, this));
	actions[ATK_R]->SetNextEvent(bind(&Mario::SetAction, this, JUMP_R));
	// SPIN_L
	actions.push_back(new Animation(texture));
	actions[SPIN_L]->SetVector({ 28, 27, 24, 26 });
	actions[SPIN_L]->SetNextEvent(bind(&Mario::SetSpin, this, false));
	actions[SPIN_L]->SetEndEvent(bind(&Mario::SetIdle, this));
	// SPIN_R
	actions.push_back(new Animation(texture));
	actions[SPIN_R]->SetVector({ 24, 27, 28, 26 });
	actions[SPIN_R]->SetNextEvent(bind(&Mario::SetSpin, this, false));
	actions[SPIN_R]->SetEndEvent(bind(&Mario::SetIdle, this));
}
