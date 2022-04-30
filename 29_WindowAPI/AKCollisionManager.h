#pragma once
class AKCollisionManager
{
public:
	AKCollisionManager(AKUI* _ui, AKPlayer* _player, AKBallManager* _ballManager);
	~AKCollisionManager();

private:
	AKUI* ui;
	AKPlayer* player;
	AKBallManager* ballManager;

	HBRUSH oldBrush;
	HBRUSH redBrush;

public:
	void Update();
	void Render(HDC hdc);

private:
	bool Collision(Rect* rect, Vector2 point);
	bool Collision(Rect* r1, Rect* r2);
	bool Collision(Circle* circle, Vector2 point);
	bool Collision(Circle* c1, Circle* c2);
	bool Collision(Circle* circle, Rect* rect);
};

