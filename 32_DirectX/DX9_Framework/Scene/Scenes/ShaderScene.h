#pragma once
class ShaderScene : public IScene
{
public:
	ShaderScene();
	~ShaderScene();

private:
	LPD3DXEFFECT shader;

	Texture*  texture;
	Transform transform;

	D3DXCOLOR color;

public:
	// IScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;


};