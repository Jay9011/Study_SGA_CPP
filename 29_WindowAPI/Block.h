#pragma once
class Block : public Object
{
public:
	Block(Texture* texture);
	~Block() override;

	void Update();
	void Render();

	bool& IsActive() { return isActive; }

private:
	bool isActive;

};

