#include "Framework.h"
#include "Landscape.h"

Landscape::Landscape()
{
    texture = TextureManager::Get()->AddTexture("Land", L"Textures/mario_tile1.png");
    
    rect = new Rect({ WIN_CENTER_X, WIN_HEIGHT * 0.9 }, { WIN_WIDTH, texture->GetFrameSize().y });

}

Landscape::~Landscape()
{
    delete rect;
}

void Landscape::Update()
{
}

void Landscape::Render()
{
    texture->Render(rect);
}
