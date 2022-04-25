#include "Framework.h"

/*
파일 입출력(File Stream)
*/

void Save()
{
	//ofstream saveFile;				   //Output File Stream
	//saveFile.open("save.txt", ios::out); //파일 이름이 존재하지 않으면 새로 만들어주고, 존재하면 덮어씌운다

	ofstream saveFile("save.txt", ios::out);

	for (UINT i = 1; i < 10; i++)
	{
		saveFile << i << endl;
	}

	//saveFile << "Hello World" << endl;

	saveFile.close();
}

void Load()
{
	//ifstream loadFile;
	//loadFile.open("save.txt", ios::in);

	ifstream loadFile("ItemList.txt", ios::in);

	string str;

	char c[100];

	loadFile.getline(c, sizeof(c));

	//getline(loadFile, str);

	cout << c << endl;

	/*vector<int> data;

	while (true)
	{
		int temp;

		loadFile >> temp;

		if (loadFile.eof())
			break;

		data.push_back(temp);
	}

	for (int i : data)
	{
		cout << i << endl;
	}*/

	loadFile.close();
}

int main()
{
	//Save();
	Load();
}