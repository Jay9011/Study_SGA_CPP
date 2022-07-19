#pragma once

class Texture
{
public:
	Texture(LPDIRECT3DTEXTURE9 texture, Vector2 start, Vector2 end, Vector2 pivot = Vector2(0.5f, 0.5f));
	Texture
	(
		LPDIRECT3DTEXTURE9 texture, 
		int maxFrameX, int maxFrameY, 
		int frameX, int frameY, 
		Vector2 pivot = Vector2(0.5f, 0.5f)
	);

	~Texture();

	void Render();

	void SetData();
	void SetSize(Vector2 size);

	LPDIRECT3DTEXTURE9 GetTexture() { return texture; }

	Vector2 GetUVStart() { return uvStart; }
	Vector2 GetUVEnd()   { return uvEnd; }

	Vector2 GetImageSize() { return imageSize; }	// ���� ������
	Vector2 GetSize()      { return size; }	// ��ȯ �� ������

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

	Vector2 imageSize;

	//Buffer
	LPDIRECT3DVERTEXBUFFER9 vertexBuffer;
	LPDIRECT3DINDEXBUFFER9   indexBuffer;
};
