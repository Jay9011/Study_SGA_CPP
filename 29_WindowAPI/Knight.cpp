#include "Framework.h"
#include "Knight.h"

Knight::Knight()
	: state(ATTACK)
{
	texture = TextureManager::Get()->AddTexture("Knight", L"Textures/Knight_All.png");

	rect = new Rect({ WIN_CENTER_X, WIN_CENTER_Y }, { 200, 200 });

	LoadXML("Textures/Knight_All.xml");

	actions[state]->IsLoop() = true;
	actions[state]->Play();
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
	if (KEY_DOWN('1'))
	{
		state = ATTACK;
		actions[state]->Play();
	}
	else if (KEY_DOWN('2'))
	{
		state = BLOCK;
		actions[state]->Play();
	}
	else if (KEY_DOWN('3'))
	{
		state = CAST;
		actions[state]->Play();
	}
	else if (KEY_DOWN('4'))
	{
		state = CROUCH;
		actions[state]->Play();
	}
	else if (KEY_DOWN('5'))
	{
		state = DASH;
		actions[state]->Play();
	}

	actions[state]->Update();
}

void Knight::Render()
{
	texture->Render(rect, actions[state]->GetXMLFrame());
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
