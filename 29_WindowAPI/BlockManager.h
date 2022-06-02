#pragma once
class BlockManager
{
public:
	BlockManager(Texture* texture, UINT poolCount);
	~BlockManager();

	void Update();
	void Render();

	vector<Block*> GetBlocks() { return blocks; }

private:
	vector<Block*> blocks;

};
