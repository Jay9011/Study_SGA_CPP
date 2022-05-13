#include "Framework.h"
#include "Enemy.h"

Enemy::Enemy()
	: type(ENEMY_TYPE::END)
	, maxHp(1)
	, curHp(maxHp)
	, velocity(3)
	, spawnPoint(nullptr)
	, arrivalPoint(nullptr)
	, bodyImg(nullptr)
	, bodyFrame({ 0, 0 })
	, frameTime(0)
	, oldpen(nullptr)
	, oldbrush(nullptr)
{
	collider = new Rect({ 0, 0 }, { 0, 0 });
	bodyImgRect = new Rect({ 0, 0 }, { 0, 0 });

	// Debug
	pen = CreatePen(PS_SOLID, 1, COLOR_RED);
	brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	OutputDebugString(L"Enemy 생성\n");
}

Enemy::~Enemy()
{
	delete bodyImgRect;
	delete collider;

	// Debug
	DeleteObject(pen);
	OutputDebugString(L"~Enemy 소멸\n");
}

void Enemy::Update()
{
}

void Enemy::Render(HDC hdc)
{
	if (!bodyImg)
	{
		OutputDebugString(L"!!! BodyImg 없음 (Enemy)\n");
		return;
	}

	bodyImg->Render(bodyImgRect, bodyFrame);

	// Debug
	oldpen = (HPEN)SelectObject(hdc, pen);
	oldbrush = (HBRUSH)SelectObject(hdc, brush);
	collider->Render(hdc);
	SelectObject(hdc, oldpen);
	SelectObject(hdc, oldbrush);
}

void Enemy::Init()
{
	type = ENEMY_TYPE::END;
	maxHp = 1;
	curHp = maxHp;
	spawnPoint = nullptr;
	arrivalPoint = nullptr;
	collider->Pos() = Vector2(0, 0);
	collider->Size() = Vector2(0, 0);
	bodyImg = nullptr;
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
		collider->Size() = Vector2(32, 32);

		break;
	default:
		Init();
		break;
	}

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
