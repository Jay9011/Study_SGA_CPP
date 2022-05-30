#include "Framework.h"
#include "Object.h"

Object::Object(Texture* _texture)
	: texture (_texture)
{
	rect = new Rect({ 0, 0 }, texture->GetFrameSize());
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
