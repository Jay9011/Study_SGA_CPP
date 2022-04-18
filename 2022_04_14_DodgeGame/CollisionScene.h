#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	// 사각형과 점의 충돌
	bool Collision(Rect* rect, Point point);
	// 사각형과 사각형의 충돌
	bool Collision(Rect* r1, Rect* r2);
	// 원과 점의 충돌
	bool Collision(Circle* circle, Point point);
	// 원과 원의 충돌
	bool Collision(Circle* c1, Circle* c2);
	// 원과 사각형의 충돌
	bool Collision(Circle* circle, Rect* rect);

private:
	Circle* player;
	ProjectileList* projectiles;

	bool gameover;
	double	speed;

	HBRUSH	 redBrush;
	HBRUSH greenBrush;
	HBRUSH	blueBrush;
};
