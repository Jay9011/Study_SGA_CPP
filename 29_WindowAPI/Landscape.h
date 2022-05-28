#pragma once

namespace MarioLandscape
{
	constexpr int TILE_SIZE = 128;
	constexpr int TILE_X_COUNT = (WIN_WIDTH / TILE_SIZE) + 2;

	constexpr int BACKGROUND_X_SIZE = 740;
	constexpr int BACKGROUND_Y_SIZE = 164;
	constexpr int BACKGROUND_X_COUNT = (WIN_WIDTH / BACKGROUND_X_SIZE) + 2;
	constexpr int BACKGROUND_Y_COUNT = (WIN_HEIGHT / BACKGROUND_Y_SIZE);

	constexpr int CLOUD_X_SIZE = 344;
	constexpr int CLOUD_Y_SIZE = 128;
}

class Landscape
{
public:
	Landscape();
	~Landscape();

	void Update();
	void Render();

	Rect* GetRect() { return tileImgRect[0]; }

private:
	Texture*      tileTx;
	vector<Rect*> tileImgRect;

	Texture*      backgroundTx;
	vector<Rect*> backgroundImgRect;

	Texture*      cloudTx;
	vector<Rect*> cloudImgRect;

	double tileMoveSpeed;
	double backgroundMoveSpeed;
	double cloudMoveSpeed;
};
