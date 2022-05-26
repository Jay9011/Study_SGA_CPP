#pragma once
class Landscape
{
public:
	Landscape();
	~Landscape();

	void Update();
	void Render();

	Rect* GetRect() { return rect; }

private:
	Texture* texture;
	Rect* rect;

};
