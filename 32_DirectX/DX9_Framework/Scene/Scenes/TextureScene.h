#pragma once
class TextureScene : public IScene
{
public:
	TextureScene();
	~TextureScene();

	// IScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	LPDIRECT3DTEXTURE9 texture;

	vector<VertexTexture> vertices;
	vector<UINT>          indices;

	Transform transform;
};
