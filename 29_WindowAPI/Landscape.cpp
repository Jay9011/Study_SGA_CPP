#include "Framework.h"
#include "Landscape.h"

Landscape::Landscape()
    : tileMoveSpeed(500)
    , backgroundMoveSpeed(200)
    , cloudMoveSpeed(300)
{
    tileTx       = TextureManager::Get()->AddTexture("Land", L"Textures/mario_tile1.png");
    backgroundTx = TextureManager::Get()->AddTexture("bg", L"Textures/background.bmp");
    cloudTx      = TextureManager::Get()->AddTexture("cloud", L"Textures/mario_cloud.png");
    
    for (int i = 0; i < MarioLandscape::TILE_X_COUNT; i++)
    {
        tileImgRect.push_back(
            new Rect({ ((double)MarioLandscape::TILE_SIZE * i) - (double)MarioLandscape::TILE_SIZE, WIN_HEIGHT * 0.8 }
                   , { (double)MarioLandscape::TILE_SIZE, (double)MarioLandscape::TILE_SIZE })
        );
    }

    for (int i = 0; i < MarioLandscape::BACKGROUND_X_COUNT; i++)
    {
        for (int j = 0; j < MarioLandscape::BACKGROUND_Y_COUNT; j++)
        {
            backgroundImgRect.push_back(
                new Rect({ ((double)MarioLandscape::BACKGROUND_X_SIZE * i), (double)MarioLandscape::BACKGROUND_Y_SIZE * j + (MarioLandscape::BACKGROUND_Y_SIZE * 0.5) }
                       , { (double)MarioLandscape::BACKGROUND_X_SIZE, (double)MarioLandscape::BACKGROUND_Y_SIZE })
            );
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cloudImgRect.push_back(
            new Rect({ (400.0 * i) - 400.0 + MarioLandscape::CLOUD_X_SIZE * 0.7, 128 + (128.0 * (i % 2)) }
                   , { (double)MarioLandscape::CLOUD_X_SIZE, (double)MarioLandscape::CLOUD_Y_SIZE })
        );
    }
}

Landscape::~Landscape()
{
    for (Rect* tile : tileImgRect)
    {
        delete tile;
    }
    tileImgRect.clear();

    for (Rect* bg : backgroundImgRect)
    {
        delete bg;
    }
    backgroundImgRect.clear();

    for (Rect* cloud : cloudImgRect)
    {
        delete cloud;
    }
    cloudImgRect.clear();
}

void Landscape::Update()
{
    if (KEY_PRESS(VK_LEFT))
    {
        for (Rect*& tile : tileImgRect)
        {
            tile->Pos() += V_RIGHT * tileMoveSpeed * Time::Delta();

            if (tile->Pos().x >= (double)WIN_WIDTH + (double)MarioLandscape::TILE_SIZE)
            {
                double overSize = tile->Pos().x - ((double)WIN_WIDTH + (double)MarioLandscape::TILE_SIZE);
                tile->Pos() = Vector2({ overSize - (double)MarioLandscape::TILE_SIZE, tile->Pos().y });
            }
        }

        for (Rect*& bg : backgroundImgRect)
        {
            bg->Pos() += V_RIGHT * backgroundMoveSpeed * Time::Delta();

            if (bg->Left() >= (double)WIN_WIDTH + MarioLandscape::BACKGROUND_X_SIZE * 0.2)
            {
                double posY = bg->Pos().y;
                Rect* minRect = bg;
                // 같은 y 위치의 Rect 중 x값이 제일 작은 값을 저장.
                for (Rect*& i : backgroundImgRect)
                {
                    if (   i->Pos().y <= posY + posY * 0.2
                        && i->Pos().y >= posY - posY * 0.2
                        && i->Pos().x <= minRect->Pos().x)
                    {
                        minRect = i;
                    }
                }
                bg->Pos().x = minRect->Pos().x - MarioLandscape::BACKGROUND_X_SIZE + 20;
            }
        }

        for (Rect*& cloud : cloudImgRect)
        {
            cloud->Pos() += V_RIGHT * cloudMoveSpeed * Time::Delta();

            if (cloud->Left() >= (double)WIN_WIDTH)
            {
                cloud->Pos().x = -MarioLandscape::CLOUD_X_SIZE * 0.5;
            }
        }
    }

    if (KEY_PRESS(VK_RIGHT))
    {
        for (Rect*& tile : tileImgRect)
        {
            tile->Pos() += V_LEFT * tileMoveSpeed * Time::Delta();

            if (tile->Pos().x <= -(double)MarioLandscape::TILE_SIZE)
            {
                double overSize = -(double)MarioLandscape::TILE_SIZE - tile->Pos().x;
                tile->Pos() = Vector2({ ((double)WIN_WIDTH + (double)MarioLandscape::TILE_SIZE) - overSize, tile->Pos().y });
            }
        }
        for (Rect*& bg : backgroundImgRect)
        {
            bg->Pos() += V_LEFT * backgroundMoveSpeed * Time::Delta();

            if (bg->Right() <= -MarioLandscape::BACKGROUND_X_SIZE * 0.2)
            {
                double posY = bg->Pos().y;
                Rect* maxRect = bg;
                // 같은 y 위치의 Rect 중 x값이 제일 큰 값을 저장.
                for (Rect*& i : backgroundImgRect)
                {
                    if (i->Pos().y <= posY + posY * 0.2
                        && i->Pos().y >= posY - posY * 0.2
                        && i->Pos().x >= maxRect->Pos().x)
                    {
                        maxRect = i;
                    }
                }
                bg->Pos().x = maxRect->Pos().x + MarioLandscape::BACKGROUND_X_SIZE - 20;
            }
        }
        for (Rect*& cloud : cloudImgRect)
        {
            cloud->Pos() += V_LEFT * cloudMoveSpeed * Time::Delta();

            if (cloud->Right() <= 0)
            {
                cloud->Pos().x = WIN_WIDTH + MarioLandscape::CLOUD_X_SIZE * 0.5;
            }
        }
    }
}

void Landscape::Render()
{
    for (Rect* bg : backgroundImgRect)
    {
        backgroundTx->Render(bg);
    }
    for (Rect* cloud : cloudImgRect)
    {
        cloudTx->Render(cloud);
    }
    for (Rect* tile : tileImgRect)
    {
        tileTx->Render(tile);
    }
}
