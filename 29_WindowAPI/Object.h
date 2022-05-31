#pragma once
class Object
{
public:
	Object(Texture* _texture);
	virtual ~Object();

	virtual void Render();
	virtual void Render(POINT frame);

	Rect* GetRect() const { return rect; }

protected:
	Texture* texture;
	Rect*    rect;
};

