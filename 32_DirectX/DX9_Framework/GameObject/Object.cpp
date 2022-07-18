#include "Framework.h"
#include "Object.h"

Object::Object(wstring file, Vector2 size)
{
	shader = Shader::Add(L"ObjectShader");

	texture = TEXTURE->Add(file);

	if (size.x != 0 && size.y != 0)
		texture->SetSize(size);
}

Object::~Object()
{
}

void Object::Update()
{
	UpdateWorld();
}

void Object::Render()
{
	SetWorld();

	shader->Begin();
	texture->Render();
	shader->End();
}
