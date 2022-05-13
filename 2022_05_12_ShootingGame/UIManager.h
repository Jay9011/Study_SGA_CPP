#pragma once
class UIManager
{
	SNG_CREATE(UIManager)
private:
	UIManager();
	~UIManager();

public:
	void Update();
	void Render(HDC hdc);

};

