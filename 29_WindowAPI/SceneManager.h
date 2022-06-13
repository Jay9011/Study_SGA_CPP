#pragma once
class SceneManager
{
private:
	SceneManager();
	~SceneManager();

public:
	static void Create();
	static void Delete();
	static SceneManager* Get();

	void Update();
	void Render(HDC hdc);

	Scene* Add(string key, Scene* scene);

	void ChangeScene(string key);
	
private:
	static SceneManager* instance;
	
	map<string, Scene*> scenes;
	Scene* curScene;
};
