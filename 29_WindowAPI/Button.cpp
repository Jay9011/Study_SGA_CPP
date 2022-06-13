#include "Framework.h"
#include "Button.h"

Button::Button(Texture* up, Texture* down, Texture* over, Vector2 pos)
	: state(UP)
	, Event(nullptr)
{
	textures[UP]   = up;
	textures[DOWN] = down;
	textures[OVER] = over;

	rect = new Rect(pos, up->GetFrameSize());
}

Button::~Button()
{
	if(rect != nullptr)
		delete rect;
}

void Button::Update()
{
	if (Collision::Collision(rect, mousePos))
	{
		state = OVER;

		if (KEY_UP(VK_LBUTTON))
		{
			if (Event != nullptr)
				Event();
		}

		if (KEY_PRESS(VK_LBUTTON))
		{
			state = DOWN;
		}
	}
	else
	{
		state = UP;
	}
}

void Button::Render()
{
	switch (state)
	{
	case Button::UP:
		textures[UP]->Render(rect);
		break;
	case Button::DOWN:
		textures[DOWN]->Render(rect);
		break;
	case Button::OVER:
		textures[OVER]->Render(rect);
		break;
	default:
		break;
	}
}
