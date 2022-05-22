#pragma once
class Bullet : public GameObject
{
public:
	Bullet(Texture* _bulletImg, Texture* _destroyImg);
	virtual ~Bullet();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	bool IsUse() { return isUse; }
	Circle* GetCollider() { return collider; }

	virtual void Fire(Vector2 pos, Vector2 dir) = 0;
	virtual void Destroy();

protected:
	virtual void ResetBullet();

	// Bullet Setting
	bool		isUse;
	bool		isDestroying;

	int			damage;

	double		velocity;
	Vector2		direction;

	Circle*		collider;
	Texture*	bulletImg;
	Rect*		bulletImgRect;
	Vector2		bulletImgRectSize;
	POINT		bulletFrame;

	Texture*	destroyImg;
	Rect*		destroyImgRect;
	Vector2		destroyImgRectSize;
	POINT		destroyFrame;

	double		frameTime;
	double		destroyTime;

private:
	// Debug Object
	HPEN	oldpen;
	HBRUSH	oldbrush;
	HPEN	pen;
	HBRUSH	brush;
};

