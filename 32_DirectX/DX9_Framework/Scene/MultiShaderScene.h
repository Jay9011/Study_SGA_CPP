#pragma once

class MultiShaderScene : public Scene
{
public:
	MultiShaderScene();
	~MultiShaderScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	Mario* mario;

	Object* background;
};
