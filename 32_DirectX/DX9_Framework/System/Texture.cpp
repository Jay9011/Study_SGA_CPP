#include "Framework.h"
#include "Texture.h"

Texture::Texture(LPDIRECT3DTEXTURE9 texture, Vector2 start, Vector2 end, Vector2 pivot) :
	texture(texture),
	pivot(pivot)
{
	D3DSURFACE_DESC surface;
	texture->GetLevelDesc(0, &surface);

	size = Vector2(surface.Width, surface.Height);

	halfSize = size * .5f;

	uvStart.x = start.x / size.x;
	uvStart.y = start.y / size.y;

	uvEnd.x = (end.x == 0.0f) ? 1.0f : end.x / size.x;
	uvEnd.y = (end.y == 0.0f) ? 1.0f : end.y / size.y;

	SetData();
}

Texture::~Texture()
{
	texture->Release();

	if (vertices != nullptr)
	{
		delete[] vertices;
		vertices = nullptr;
	}

	if (indices != nullptr)
	{
		delete[] indices;
		indices = nullptr;
	}
}

void Texture::Render()
{
	DEVICE->SetFVF(VertexTexture::fvf);
	DEVICE->SetTexture(0, texture);

	DEVICE->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, vertexCount, indexCount / 3, indices, D3DFMT_INDEX16, vertices, sizeof(VertexTexture));
}

void Texture::SetData()
{
	vertexCount = 4;
	vertices = new VertexTexture[vertexCount];

	vertices[0] = VertexTexture(-size.x * pivot.x      , -size.y * pivot.y      , uvStart.x, uvStart.y);
	vertices[1] = VertexTexture(+size.x * (1 - pivot.x), -size.y * pivot.y      , uvEnd.x  , uvStart.y);
	vertices[2] = VertexTexture(-size.x * pivot.x      , +size.y * (1 - pivot.y), uvStart.x, uvEnd.y);
	vertices[3] = VertexTexture(+size.x * (1 - pivot.x), +size.y * (1 - pivot.y), uvEnd.x  , uvEnd.y);

	indexCount = 6;
	indices = new WORD[indexCount]{ 0, 1, 2, 2, 1, 3 };

}
