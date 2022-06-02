#pragma once
namespace Collision
{
	//�簢���� ���� �浹
	bool Collision(Rect*   rect	, Vector2 point);
	bool Collision(Vector2 point, Rect* rect);

	//�簢���� �簢���� �浹
	bool Collision(Rect* r1, Rect* r2);

	//���� ���� �浹
	bool Collision(Circle* circle, Vector2 point);
	bool Collision(Vector2 point , Circle* circle);

	//���� ���� �浹
	bool Collision(Circle* c1, Circle* c2);

	//���� �簢���� �浹
	bool Collision(Circle* circle, Rect* rect);
	bool Collision(Rect*   rect	 , Circle* circle);

	// ���� ���� �浹
	bool Collision(Line* line1, Line* line2);

	/* * * * * * * * * * * * * * * * *
	*	�浹���� ���� �����ϱ�
	* * * * * * * * * * * * * * * * */
	bool Collision(OUT Rect* overlap, IN Rect* r1, IN Rect* r2);
}