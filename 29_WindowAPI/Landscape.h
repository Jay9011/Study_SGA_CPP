#pragma once

#define BACKGROUND	3
#define LAND		12

class Landscape
{
public:
	Landscape();
	~Landscape();

	void Update();
	void Render();

	void CreateBackground();
	void CreateLand();

	vector<Object*> GetLands() const       { return lands; }
	vector<Object*> GetBackgrounds() const { return backgrounds; }

private:
	vector<Object*> backgrounds;
	double          bgSpeed;

	vector<Object*> lands;
	double          landSpeed;
};
