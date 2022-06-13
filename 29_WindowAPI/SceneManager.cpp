#include "Framework.h"
#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
	: curScene(nullptr)
{
}

SceneManager::~SceneManager()
{
	curScene->Release();

	for (pair<string, Scene*> scene : scenes)
		delete scene.second;

	scenes.clear();
}

void SceneManager::Create()
{
	if (instance == nullptr)
		instance = new SceneManager;
}

void SceneManager::Delete()
{
	if (instance != nullptr)
		delete instance;

	instance = nullptr;
}

SceneManager* SceneManager::Get()
{
	return instance;
}

void SceneManager::Update()
{
	if (curScene == nullptr)
		return;

	curScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	if (curScene == nullptr)
		return;

	curScene->Render(hdc);
}

Scene* SceneManager::Add(string key, Scene* scene)
{
	if (scenes.count(key) > 0)
		return scenes[key];

	scenes.emplace(key, scene);

	return scene;
}

void SceneManager::ChangeScene(string key)
{
	if (scenes.count(key) == 0)
		return;

	if (scenes[key] == curScene)
		return;

	if (curScene != nullptr)
		curScene->Release();

	curScene = scenes[key];
	curScene->Initialize();
}
