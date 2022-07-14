#pragma once

class TextureScene : public Scene
{
public:
	TextureScene();
	~TextureScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	LPDIRECT3DTEXTURE9 texture;

	vector<VertexTexture> vertices;
	vector<UINT>           indices;

	Transform transform;
	Transform transform2;

	Texture* IDLE;
};
