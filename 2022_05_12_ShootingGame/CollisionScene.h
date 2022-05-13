#pragma once

class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	//�簢���� ���� �浹
	bool Collision(Rect* rect, Vector2 point);

	//�簢���� �簢���� �浹
	bool Collision(Rect* r1, Rect* r2);

	//���� ���� �浹
	bool Collision(Circle* circle, Vector2 point);

	//���� ���� �浹
	bool Collision(Circle* c1, Circle* c2);

	//���� �簢���� �浹
	bool Collision(Circle* circle, Rect* rect);

	// ���� ���� �浹
	bool Collision(Line* line1, Line* line2);

private:
	Rect* rect1;
	Rect* rect2;

	Circle* circle1;
	Circle* circle2;

	Line* line1;
	Line* line2;

	double speed;

	HBRUSH   redBrush;
	HBRUSH greenBrush;
	HBRUSH  blueBrush;
	
	HPEN	  redPen;
	HPEN	greenPen;
};