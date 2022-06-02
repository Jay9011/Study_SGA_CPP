#include "Framework.h"
#include "BlockManager.h"

BlockManager::BlockManager(Texture* texture, UINT poolCount)
{
	for (UINT i = 0; i < poolCount; i++)
	{
		Block* block = new Block(texture);

		Vector2 pos;

		pos.x = WIN_CENTER_X + i * block->GetRect()->Size().x;
		pos.y = WIN_CENTER_Y + 50;

		block->GetRect()->Pos() = pos;
		block->IsActive() = true;

		blocks.push_back(block);
	}
}

BlockManager::~BlockManager()
{
	for (Block* block : blocks)
		delete block;
}

void BlockManager::Update()
{
	for (Block* block : blocks)
		block->Update();
}

void BlockManager::Render()
{
	for (Block* block : blocks)
		block->Render();
}
