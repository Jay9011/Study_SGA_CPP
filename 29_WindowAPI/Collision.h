#pragma once
namespace Collision
{
	//사각형과 점의 충돌
	bool Collision(Rect*   rect	, Vector2 point);
	bool Collision(Vector2 point, Rect* rect);

	//사각형과 사각형의 충돌
	bool Collision(Rect* r1, Rect* r2);

	//원과 점의 충돌
	bool Collision(Circle* circle, Vector2 point);
	bool Collision(Vector2 point , Circle* circle);

	//원과 원의 충돌
	bool Collision(Circle* c1, Circle* c2);

	//원과 사각형의 충돌
	bool Collision(Circle* circle, Rect* rect);
	bool Collision(Rect*   rect	 , Circle* circle);

	// 선과 선의 충돌
	bool Collision(Line* line1, Line* line2);

	/* * * * * * * * * * * * * * * * *
	*	충돌에서 방향 추측하기
	* * * * * * * * * * * * * * * * */
	bool Collision(OUT Rect* overlap, IN Rect* r1, IN Rect* r2);
}