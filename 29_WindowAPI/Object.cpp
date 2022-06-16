#include "Framework.h"
#include "Object.h"

Object::Object()
{
}

Object::Object(Texture* _texture)
	: texture (_texture)
{
	rect = new Rect({ WIN_CENTER_X, WIN_CENTER_Y }, texture->GetFrameSize());
}

Object::~Object()
{
	delete rect;
}

void Object::Render()
{
	texture->Render(rect);
}

void Object::Render(POINT frame)
{
	texture->Render(rect, frame);
}

void Object::Render(Vector2 pos)
{
	Rect temp = *rect;
	temp.Pos() -= Camera::Get()->Pos();

	texture->Render(&temp);
}

void Object::Render(POINT frame, Vector2 pos)
{
	Rect temp = *rect;
	temp.Pos() -= Camera::Get()->Pos();

	texture->Render(&temp, frame);
}
