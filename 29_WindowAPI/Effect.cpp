#include "Framework.h"
#include "Effect.h"

CEffect::CEffect(Texture* texture, double speed)
	: texture(texture)
	, isActive(false)
{
	animation = new Animation(texture, speed);
	animation->SetDefault();
	animation->SetEndEvent(bind(&CEffect::Stop, this));

	rect = new Rect({ 0, 0 }, texture->GetFrameSize());
}

CEffect::~CEffect()
{
	delete rect;
	delete animation;
}

void CEffect::Update()
{
	if (!isActive)
		return;

	animation->Update();
}

void CEffect::Render()
{
	if (!isActive)
		return;

	texture->Render(rect, animation->GetFrame());
}

void CEffect::Play(Vector2 pos)
{
	isActive = true;
	rect->Pos() = pos;
	animation->Play();
}

void CEffect::Stop()
{
	isActive = false;
	animation->Stop();
}
