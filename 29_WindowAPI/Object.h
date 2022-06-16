#pragma once
class Object
{
public:
	Object();
	Object(Texture* _texture);
	virtual ~Object();

	virtual void Render();
	virtual void Render(POINT frame);

	// Camera
	virtual void Render(Vector2 pos);
	virtual void Render(POINT frame, Vector2 pos);

	Rect* GetRect() const { return rect; }

protected:
	Texture* texture;
	Rect*    rect;
};

