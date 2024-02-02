#include "SceneTitle.h"
#include "Novice.h"

cSceneTitle::cSceneTitle()
{
	Init();
}

cSceneTitle::~cSceneTitle()
{

}

void cSceneTitle::Init()
{
	selectMenu = GAMESTART;
}

void cSceneTitle::Update(char* keys, char* preKeys, eScene& nextScene)
{
	if (keys[DIK_W] && !preKeys[DIK_W])
	{
		selectMenu++;
	}
	if (keys[DIK_S] && !preKeys[DIK_S])
	{
		selectMenu--;
	}
	if (selectMenu > 1)
	{
		selectMenu = 0;
	}
	if (selectMenu < 0)
	{
		selectMenu = 1;
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
	{
		switch (selectMenu)
		{
		case GAMESTART:
			nextScene = GAME;
			break;
		case EXIT:
			exit(0);
			break;
		default:
			break;
		}
	}
}

void cSceneTitle::Draw()
{

}

void cSceneTitle::DrawDebug()
{
	Novice::ScreenPrintf(12, 24, "currentScene: TITLE");
}
