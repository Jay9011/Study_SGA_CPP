#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	// �簢���� ���� �浹
	bool Collision(Rect* rect, Point point);
	// �簢���� �簢���� �浹
	bool Collision(Rect* r1, Rect* r2);
	// ���� ���� �浹
	bool Collision(Circle* circle, Point point);
	// ���� ���� �浹
	bool Collision(Circle* c1, Circle* c2);
	// ���� �簢���� �浹
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
