#include "Framework.h"
#include "Enemy.h"

Enemy::Enemy()
	: type(ENEMY_TYPE::END)
	, maxHp(1)
	, curHp(maxHp)
	, velocity(180)
	, direction({ 0, 0 })
	, spawnPoint(nullptr)
	, arrivalPoint(nullptr)
	, bodyImg(nullptr)
	, bodyFrame({ 0, 0 })
	, frameTime(0)
	, reloadTime(0)
	, oldpen(nullptr)
	, oldbrush(nullptr)
{
	collider = new Rect({ 0, 0 }, { 0, 0 });
	bodyImgRect = new Rect({ 0, 0 }, { 0, 0 });

	// Debug
	//pen = CreatePen(PS_SOLID, 1, COLOR_RED);
	//brush = (HBRUSH)GetStockObject(NULL_BRUSH);
}

Enemy::~Enemy()
{
	delete bodyImgRect;
	delete collider;

	// Debug
	//DeleteObject(pen);
}

void Enemy::Update()
{
	if (type != ENEMY_TYPE::END)
	{
		frameTime += Time::Delta();
		if (frameTime > 0.2)
		{
			frameTime = 0;
			++bodyFrame.x %= 2;
		}

		if (velocity != 0)
		{
			Move();
		}

		bodyImgRect->Pos() = collider->Pos();

		// Enemy Fire
		reloadTime += Time::Delta();
		if (reloadTime > 1.3)
		{
			reloadTime = 0;
			Vector2 bulletPos = { collider->Pos().x
								, collider->Bottom() };

			Vector2 bulletDirection =
				PlayerManager::Get()->player->GetCollider()->Pos()
				- bulletPos;
			bulletDirection.Normalize();

			BulletManager::Get()->EnemyFire(bulletPos, bulletDirection);
		}

		// Collision Check
		for (auto& bullet : BulletManager::Get()->playerBullet)
		{
			if (!(bullet->IsUse()))
				continue;

			if (Collision::Collision(collider, bullet->GetCollider()))
			{
				bullet->Destroy();
				--curHp;

				if (curHp < 1)
				{
					PlayerManager::Get()->player->SetScore(maxHp);
					Destroy();
				}
			}
		}
	}
}

void Enemy::Render(HDC hdc)
{
	if (type != ENEMY_TYPE::END)
	{
		if (!bodyImg)
		{
			OutputDebugString(L"!!! BodyImg ¾øÀ½ (Enemy)\n");
			return;
		}

		bodyImg->Render(bodyImgRect, bodyFrame);

		// Debug
		//oldpen = (HPEN)SelectObject(hdc, pen);
		//oldbrush = (HBRUSH)SelectObject(hdc, brush);
		//collider->Render(hdc);
		//SelectObject(hdc, oldpen);
		//SelectObject(hdc, oldbrush);
	}
}

void Enemy::Init()
{
	type = ENEMY_TYPE::END;
	maxHp = 1;
	curHp = maxHp;

	velocity = 180;

	spawnPoint->isUse = false;
	spawnPoint = nullptr;
	
	arrivalPoint->isUse = false;
	arrivalPoint = nullptr;
	
	bodyImg = nullptr;
	collider->Pos() = Vector2(0, 0);
	collider->Size() = Vector2(0, 0);
	bodyImgRect->Pos() = Vector2(0, 0);
	bodyImgRect->Size() = Vector2(0, 0);
	
	frameTime = 0;
}

void Enemy::Setting(ENEMY_TYPE type)
{
	switch (type)
	{
	case ENEMY_TYPE::S:
		maxHp = 1;
		collider->Size() = Vector2(16, 16);
		
		break;
	case ENEMY_TYPE::M:
		maxHp = 2;
		collider->Size() = Vector2(32, 16);

		break;
	case ENEMY_TYPE::L:
		maxHp = 3;
		collider->Size() = Vector2(28, 30);

		break;
	default:
		Init();
		break;
	}

	this->type = type;
	curHp = maxHp;
}

void Enemy::Setting(ENEMY_TYPE type, Texture* texture)
{
	bodyImg = texture;

	switch (type)
	{
	case ENEMY_TYPE::S:
		bodyImgRect->Size() = Vector2(16, 16);
		break;
	case ENEMY_TYPE::M:
		bodyImgRect->Size() = Vector2(32, 16);
		break;
	case ENEMY_TYPE::L:
		bodyImgRect->Size() = Vector2(32, 32);
		break;
	default:
		break;
	}

	Setting(type);
}

void Enemy::Setting(ENEMY_TYPE type, Texture* texture, PointFlag* spawn, PointFlag* arrive)
{
	spawnPoint = spawn;
	arrivalPoint = arrive;
	arrivalPoint->isUse = true;
	collider->Pos() = spawnPoint->pos;
	Setting(type, texture);
}

void Enemy::Move()
{
	double distance = Math::Distance(arrivalPoint->pos, collider->Pos());
	if (distance > 50)
	{
		velocity = 180;
	}
	else if (distance > 20)
	{
		velocity = 120;
	}
	else if (distance > 10)
	{
		velocity = 60;
	}
	else
	{
		velocity = 0;
	}
	
	direction = arrivalPoint->pos - collider->Pos();
	direction.Normalize();

	collider->Pos() += direction * velocity * Time::Delta();
}

void Enemy::Destroy()
{
	Init();
}
