#pragma once
class Object
{
public:
	Object(Texture* _texture);
	~Object();

	virtual void Render();
	virtual void Render(POINT frame);

	Rect* GetRect() const { return rect; }

private:
	Texture* texture;
	Rect*    rect;
};

