#pragma once
class Texture
{
public:
	Texture(LPDIRECT3DTEXTURE9 texture, Vector2 start, Vector2 end, Vector2 pivot = Vector2(.5f, .5f));
	Texture(LPDIRECT3DTEXTURE9 texture, int maxFrameX, int maxFrameY, int frameX, int frameY, Vector2 pivot = Vector2(.5f, .5f));
	~Texture();

	void Render();
	
	void SetData();


private:
	VertexTexture* vertices;
	WORD*          indices;

	UINT vertexCount;
	UINT  indexCount;

	LPDIRECT3DTEXTURE9 texture;

	Vector2 size;
	Vector2 halfSize;

	Vector2 uvStart;
	Vector2 uvEnd;

	Vector2 pivot;

	// Buffer
	LPDIRECT3DVERTEXBUFFER9 vertexBuffer;
	LPDIRECT3DINDEXBUFFER9 indexBuffer;
};
