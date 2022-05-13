#pragma once
class PlayerManager
{
	SNG_CREATE(PlayerManager)
private:
	PlayerManager();
	~PlayerManager();

public:
	void Update();
	void Render(HDC hdc);

private:
	GameObject* player;

};

