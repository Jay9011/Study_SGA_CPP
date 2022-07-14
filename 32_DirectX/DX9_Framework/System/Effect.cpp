#include "Framework.h"
#include "Effect.h"

Effect::Effect(wstring file, int maxFrameX, int maxFrameY, bool isAdditive, float speed)
	:isActive(false), isAdditive(isAdditive), color(1.0f, 1.0f, 1.0f, 1.0f)
{
	file = L"Textures/Effects/" + file;

	vector<Texture*> actions;

	for (int y = 0; y < maxFrameY; y++)
	{
		for (int x = 0; x < maxFrameX; x++)
		{
			actions.push_back(TEXTURE->Add(file, maxFrameX, maxFrameY, x, y));
		}
	}

	animation = new Animation(actions, END, speed);
	animation->SetEndEvent(bind(&Effect::End, this));

	shader = Shader::Add(L"AlphaShader");
}

Effect::~Effect()
{
	delete animation;
}

void Effect::Update()
{
	if (!isActive)
		return;

	animation->Update();
	UpdateWorld();
}

void Effect::Render()
{
	if (!isActive)
		return;

	SetWorld();

	shader->SetArray("Color", &color, 4);
	shader->Begin(isAdditive);

	animation->Render();

	shader->End();
}

void Effect::Play(Vector2 pos, D3DXCOLOR color)
{
	isActive = true;

	this->pos   = pos;
	this->color = color;

	animation->Play();
}

void Effect::End()
{
	isActive = false;
}
