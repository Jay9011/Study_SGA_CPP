#pragma once

class PaintScene : public Scene
{
public:
	PaintScene();
	~PaintScene();

private:
	enum Type
	{
		PEN,
		LINE,
		RECT,
		ELLIPSE
	} type;

	enum Color
	{
		RED,
		GREEN,
		BLUE
	} color;

	struct Data
	{
		Point startPos;
		Point	endPos;
		Color	 color;
		Type	  type;
	};

	HDC hdc;

	Point	startPos;
	Point	  endPos;

	HPEN	 hPen[3];
	HBRUSH hBrush[3];

	bool isClick;
	bool isPreview;

	vector<Data> objects;

public:
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetType();

	void LButtonDown();
	void LButtonUp();

	void DrawPen();

	void Preview();
};
