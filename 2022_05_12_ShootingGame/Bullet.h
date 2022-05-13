#pragma once
class Bullet : public GameObject
{
public:
	Bullet(Texture* texture);
	virtual ~Bullet();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	bool IsUse() { return isUse; }
	virtual void Fire(Vector2 pos, Vector2 dir) = 0;

protected:
	virtual void ResetBullet();

	// Bullet Setting
	bool		isUse;
	double		velocity;
	Vector2		direction;

	Circle*		collider;
	Texture*	bulletImg;
	Rect*		bulletImgRect;
	POINT		bulletFrame;

	int			frameTime;

private:
	// Debug Object
	HPEN	oldpen;
	HBRUSH	oldbrush;
	HPEN	pen;
	HBRUSH	brush;
};

