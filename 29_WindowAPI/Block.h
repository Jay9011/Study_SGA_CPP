#pragma once
class Block : public Object
{
public:
	Block(Texture* texture);
	~Block() override;

	void Update();
	void Render();

private:
	bool isActive;

};

