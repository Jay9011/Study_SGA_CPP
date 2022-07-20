#pragma once
class VertexShaderScene : public Scene
{
public:
	VertexShaderScene();
	~VertexShaderScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	Camera* camera;
	Object* IDLE;



};

