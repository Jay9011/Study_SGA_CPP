#include "Framework.h"
#include "Enemy.h"

Enemy::Enemy()
	: speed(10)
	, frame({0, 0})
	, isActive(false)
	, time(0)
	, randomTime(0)
{
	texture = TextureManager::Get()->AddTexture("Enemy", L"Textures/ufo.png", 10, 1);

	rect = new Rect
	(
		{ WIN_CENTER_X      , WIN_CENTER_Y * 0.1 }, 
		{ (double)texture->GetFrameSize().x, (double)texture->GetFrameSize().y }
	);

}

Enemy::Enemy(Vector2 _pos)
	: speed(10)
	, frame({ 0, 0 })
	, isActive(false)
	, time(0)
	, randomTime(0)
{
	texture = TextureManager::Get()->AddTexture("Enemy", L"Textures/ufo.png", 10, 1);

	rect = new Rect(_pos, { (double)texture->GetFrameSize().x, (double)texture->GetFrameSize().y });
}

Enemy::~Enemy()
{
	delete rect;
}

void Enemy::Update()
{
	if (!isActive)
		return;

}

void Enemy::Render()
{
	/*if (!isActive)
		return;*/

	texture->Render(rect, frame);
}
