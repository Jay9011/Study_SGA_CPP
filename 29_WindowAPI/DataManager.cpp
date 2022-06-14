#include "Framework.h"
#include "DataManager.h"

DataManager* DataManager::instance = nullptr;

DataManager::DataManager()
{
	LoadData();
}

DataManager::~DataManager()
{
}

void DataManager::Create()
{
	if (instance == nullptr)
		instance = new DataManager;
}

void DataManager::Delete()
{
	if (instance != nullptr)
		delete instance;

	instance = nullptr;
}

DataManager* DataManager::Get()
{
	if (instance == nullptr)
		Create();

	return instance;
}

void DataManager::LoadData()
{
	ifstream loadFile("TextData/ItemTable.csv", ios::in);

	string str;

	int count = 0;

	while (true)
	{
		count++;
		loadFile >> str;

		if (count == 1)
			continue;

		string token;
		int    cutAt = 0;
		string temp;

		ItemData data;
		UINT   key;

		for (size_t i = 0; i < 8; i++)
		{
			token = ",";
			cutAt = str.find_first_of(token);
			temp  = str.substr(0, cutAt);

			// 이후 데이터만 남기기
			str = str.substr(cutAt + 1);

			switch (i)
			{
			case 0 :
				key = stoi(temp);
				break;
			case 1:
				data.name = temp;
				break;
			case 2:
				data.attack = stoi(temp);
				break;
			case 3:
				data.defense = stoi(temp);
				break;
			case 4:
				data.price = stoi(temp);
				break;
			case 5:
				data.type = stoi(temp);
				break;
			case 6:
				data.frameX = stoi(temp);
				break;
			case 7:
				data.frameY = stoi(temp);
				break;
			}
		}

		if (itemDatas.count(key) > 0)
			return;
		
		// 데이터 추가
		itemDatas.emplace(key, data);
	}
}
