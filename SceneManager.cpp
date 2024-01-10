#include "SceneManager.h"
#include "SceneGame.h"

cSceneManager::cSceneManager()
{
	Init();
	sceneGame = new cSceneGame;
}

cSceneManager::~cSceneManager()
{
	delete sceneGame;
}

void cSceneManager::Init()
{
	isDebug = true;
	currentScene = Game;
	nextScene = Game;
	prevScene = Game;
}

void cSceneManager::Update(char* keys, char* preKeys)
{
	switch (currentScene)
	{
	case Title:
		break;
	case Game:
		sceneGame->Update(keys, preKeys);
		break;
	case Result:
		break;
	default:
		break;
	}
}

void cSceneManager::Draw()
{
	switch (currentScene)
	{
	case Title:
		break;
	case Game:
		sceneGame->Draw();
		break;
	case Result:
		break;
	default:
		break;
	}
}
