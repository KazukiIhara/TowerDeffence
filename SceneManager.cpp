#include "SceneManager.h"
#include "Novice.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneResult.h"

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
	isDebug = false;
	currentScene = TITLE;
	nextScene = TITLE;
	prevScene = TITLE;
}

void cSceneManager::SceneChange()
{
	if (currentScene != nextScene)
	{
		prevScene = currentScene;
		currentScene = nextScene;
		switch (nextScene)
		{
		case TITLE:
			delete pCurrentScene;
			pCurrentScene = new cSceneTitle;
			break;
		case GAME:
			delete pCurrentScene;
			pCurrentScene = new cSceneGame;
			break;
		case RESULT:
			delete pCurrentScene;
			pCurrentScene = new cSceneResult;
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

	pCurrentScene->Update(keys, preKeys, nextScene);

}

void cSceneManager::Draw()
{
	pCurrentScene->Draw();

	if (isDebug)
	{
		pCurrentScene->DrawDebug();
	}

}
