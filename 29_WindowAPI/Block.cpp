#include "Framework.h"
#include "Block.h"

Block::Block(Texture* texture)
	: Object(texture)
	, isActive(false)
{
	rect->Size() = { 50, 50 };
	rect->Pos() = { WIN_CENTER_X, WIN_CENTER_Y };
}

Block::~Block() = default;

void Block::Update()
{

}

void Block::Render()
{
	Object::Render();
}
