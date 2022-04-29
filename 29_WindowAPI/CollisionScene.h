#pragma once

class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	//사각형과 점의 충돌
	bool Collision(Rect* rect, Vector2 point);

	//사각형과 사각형의 충돌
	bool Collision(Rect* r1, Rect* r2);

	//원과 점의 충돌
	bool Collision(Circle* circle, Vector2 point);

	//원과 원의 충돌
	bool Collision(Circle* c1, Circle* c2);

	//원과 사각형의 충돌
	bool Collision(Circle* circle, Rect* rect);

	// 선과 선의 충돌
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
