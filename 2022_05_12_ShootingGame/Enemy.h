#pragma once
class Enemy : public GameObject
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	
};

