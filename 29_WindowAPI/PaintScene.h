#pragma once


class PaintScene : public Scene
{
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
		Type  type;
		Color color;
		
		Vector2 startPos;
		Vector2   endPos;		
	};

public:
	PaintScene();
	~PaintScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetType();

	void LButtonDown();
	void LButtonUp();

	void DrawPen();

	void Preview();

private:
	Vector2 startPos;
	Vector2   endPos;

	HPEN     hPen[3];
	HBRUSH hBrush[3];

	HDC hdc;

	bool isClick;

	bool isPreview;

	vector<Data> objects;
};
