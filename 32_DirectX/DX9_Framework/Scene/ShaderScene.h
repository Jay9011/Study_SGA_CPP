#pragma once

class ShaderScene : public Scene
{
public:
	ShaderScene();
	~ShaderScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	LPD3DXEFFECT shader;

	Texture*  texture;
	Transform transform;

	D3DXCOLOR color;

	Texture* airplane;

	int passIndex;
};
