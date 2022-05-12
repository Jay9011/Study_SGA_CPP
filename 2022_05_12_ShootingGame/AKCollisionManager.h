#pragma once
class AKCollisionManager
{
public:
	AKCollisionManager(AKUI* _ui, AKPlayer* _player, AKBallManager* _ballManager, AKStageManager* _stageManager);
	~AKCollisionManager();

private:
	AKUI* ui;
	AKPlayer* player;
	AKBallManager* ballManager;
	AKStageManager* stageManager;

	HBRUSH oldBrush;
	HBRUSH redBrush;

public:
	void Update();
	void Render(HDC hdc);

private:
	bool Collision(Rect* r1, Rect* r2);
	bool Collision(Circle* circle, Vector2 point);
	bool Collision(AKBall* _ball, AKUI* _ui);
	bool Collision(AKBall* _ball, AKPlayer* _player);
	bool Collision(AKBall* _ball, AKBrick* _brick);
};

