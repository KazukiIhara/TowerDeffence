#include "SceneManager.h"
#include "SceneGame.h"
#include "Novice.h"

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
	if (keys[DIK_P] && !preKeys[DIK_P])
	{
		if (isDebug)
		{
			isDebug = false;
		}
		else
		{
			isDebug = true;
		}
	}

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
		if (isDebug)
		{
			sceneGame->DrawDebug();
		}
		break;
	case Result:
		break;
	default:
		break;
	}

}
