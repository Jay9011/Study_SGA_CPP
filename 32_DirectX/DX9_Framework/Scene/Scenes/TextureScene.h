#pragma once
class TextureScene : public IScene
{
public:
	TextureScene();
	~TextureScene();

	// IScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	LPDIRECT3DTEXTURE9 texture;

	vector<VertexTexture> vertices;
	vector<UINT>          indices;

	Transform transform;
};
