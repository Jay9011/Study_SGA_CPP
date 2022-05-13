#pragma once

enum class ObjectType
{
	PLAYER,
	PLAYER_BULLET,
	ENEMY,
	ENEMY_BULLET,
	END
};

enum class ENEMY_TYPE
{
	S,
	M,
	L,
	END
};

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;

};
