#pragma once
class VertexShaderScene : public Scene
{
public:
	VertexShaderScene();
	~VertexShaderScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	Camera* camera;
	Object* IDLE;



};

