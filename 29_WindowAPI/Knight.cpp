#include "Framework.h"
#include "Knight.h"

Knight::Knight()
	: state(IDLE)
	, curAction(0)
	, speed(100)
{
	texture = TextureManager::Get()->AddTexture("Knight", L"Textures/Knight_All.png");

	rect = new Rect({ WIN_CENTER_X, WIN_CENTER_Y }, { 200, 200 });

	LoadXML("Textures/Knight_All.xml");

	actions[state]->IsLoop() = true;
	actions[state]->Play();

	land = TextureManager::Get()->Find("Mountain");

	actions[IDLE]->IsLoop() = true;
	actions[WALK]->IsLoop() = true;

	cannonBalls = new CannonBallManager(30);
}

Knight::~Knight()
{
	delete rect;

	for (Animation*& action : actions)
		delete action;
	actions.clear();
}

void Knight::Update()
{
	if (KEY_PRESS(VK_LEFT))
	{
		rect->Pos() += V_LEFT * speed * Time::Delta();
		PlayAction(WALK);
	}
	if (KEY_PRESS(VK_RIGHT))
	{
		rect->Pos() += V_RIGHT * speed * Time::Delta();
		PlayAction(WALK);
	}

	if (KEY_UP(VK_LEFT) || KEY_UP(VK_RIGHT))
		PlayAction(IDLE);

	if (KEY_DOWN(VK_SPACE))
	{
		PlayAction(ATTACK);
		actions[ATTACK]->SetEndEvent(bind(&Knight::SetIDLE, this));
		cannonBalls->Fire(rect->Pos(), V_RUP, 100);
	}

	rect->Pos().y = land->GetLandY(rect->Pos().x) - (rect->Size().y * .5);
	
	actions[state]->Update();

	cannonBalls->Update();
}

void Knight::Render()
{
	texture->Render(rect, actions[state]->GetXMLFrame());

	cannonBalls->Render(backDC);
}

void Knight::LoadXML(string file)
{
	XmlDocument* document = new XmlDocument();
	document->LoadFile(file.c_str());

	XmlElement* atlas  = document->FirstChildElement();
	XmlElement* action =    atlas->FirstChildElement();

	while (true)
	{
		XmlElement* sprite = action->FirstChildElement();
		
		Animation* animation = new Animation;

		while (true)
		{
			RECT rect;
			rect.left   = sprite->IntAttribute("x");
			rect.top    = sprite->IntAttribute("y");
			rect.right  = sprite->IntAttribute("w");
			rect.bottom = sprite->IntAttribute("h");

			animation->SetXMLFrame(rect.left, rect.top, rect.right, rect.bottom);

			sprite = sprite->NextSiblingElement();
		
			if (sprite == nullptr)
				break;
		}

		actions.push_back(animation);
		action = action->NextSiblingElement();

		if (action == nullptr)
			break;
	}

}

void Knight::PlayAction()
{
	++curAction %= 14;
	state = (STATE)curAction;
	actions[state]->Play();
}

void Knight::PlayAction(STATE state)
{
	if (this->state == state)
		return;

	this->state = state;
	actions[state]->Play();
}
