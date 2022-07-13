#include "Framework.h"
#include "Effect.h"

Effect::Effect(wstring file, int maxFrameX, int maxFrameY, float speed) :
	isActive(false)
	, isAdditive(false)
	, color(1.0f, 1.0f, 1.0f, 1.0f)
{
	vector<Texture*> actions;

	for (int y = 0; y < maxFrameY; y++)
	{
		for (int x = 0; x < maxFrameX; x++)
		{
			actions.push_back(TEXTURE->Add(file, maxFrameX, maxFrameY, x, y));
		}
	}

	animation = new Animation(actions, END, speed);

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

void Effect::Play(Vector2 pos)
{
	isActive = true;
	this->pos = pos;

	animation->Play();
}
