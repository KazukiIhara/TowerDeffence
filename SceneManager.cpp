#include "SceneManager.h"
#include "Novice.h"
#include "SceneTitle.h"
#include "SceneGame.h"

cSceneManager::cSceneManager()
{
	Init();
	pCurrentScene = new cSceneTitle;
}

cSceneManager::~cSceneManager()
{
	delete pCurrentScene;
}

void cSceneManager::Init()
{
	isDebug = true;
	currentScene = Title;
	nextScene = Game;
	prevScene = Title;
}

void cSceneManager::SceneChange()
{
	if (currentScene != nextScene)
	{
		prevScene = currentScene;
		currentScene = nextScene;
		switch (nextScene)
		{
		case Title:
			delete pCurrentScene;
			break;
		case Game:
			delete pCurrentScene;
			pCurrentScene = new cSceneGame;
			break;
		case Result:
			break;
		default:
			break;
		}
	}
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

	pCurrentScene->Update(keys, preKeys);

}

void cSceneManager::Draw()
{
	pCurrentScene->Draw();
	if (isDebug)
	{
		pCurrentScene->DrawDebug();
	}

}
