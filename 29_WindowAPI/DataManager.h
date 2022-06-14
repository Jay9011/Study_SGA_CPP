#pragma once

struct ItemData
{
	string name;
	UINT   attack;
	UINT   defense;
	UINT   price;
	UINT   type;
	UINT   frameX;
	UINT   frameY;
};

class DataManager
{
private:
	DataManager();
	~DataManager();

public:
	static void Create();
	static void Delete();

	static DataManager* Get();

	void LoadData();

private:
	static DataManager* instance;

	map<UINT, ItemData> itemDatas;
};
