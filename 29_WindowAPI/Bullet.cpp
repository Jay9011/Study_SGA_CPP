#include "Framework.h"
#include "Bullet.h"

Bullet::Bullet()
	: speed(10)
	, dir(V_UP)
	, isFire(false)
{
	texture = TextureManager::Get()->AddTexture("Bullet", L"Textures/ball.png");
	
	rect = new Rect({ 0, 0 }, texture->GetFrameSize());
}

Bullet::~Bullet()
{
	delete rect;
}

void Bullet::Update()
{
	if (!isFire)
		return;

	rect->Pos() += dir * speed;

	// 화면 밖으로 나가는 경우
	if (   rect->Bottom() < 0
		|| rect->Top()	  > WIN_HEIGHT
		|| rect->Right()  < 0
		|| rect->Left()   > WIN_WIDTH
		)
	{
		isFire = false;
	}
}

void Bullet::Render()
{
	if (!isFire)
		return;

	texture->Render(rect);
}

void Bullet::Fire(Vector2 _pos, Vector2 _dir, double _speed)
{
	rect->Pos() = _pos;
	this->dir   = _dir;
	this->speed = _speed;

	isFire = true;
}
