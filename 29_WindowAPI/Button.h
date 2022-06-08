#pragma once

class Button
{
public:
	enum State
	{
		UP,
		DOWN,
		OVER,
	} state;

	Button(Texture* up, Texture* down, Texture* over, Vector2 pos);
	~Button();

	void Update();
	void Render();

	void SetEvent(function<void()> func) { this->Event = func; }

private:
	Texture* textures[3];
	Rect*    rect;

	function<void()> Event;

};

