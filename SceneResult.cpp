#include "SceneResult.h"
#include <Novice.h>

cSceneResult::cSceneResult()
{
	Init();
}

cSceneResult::~cSceneResult()
{

}

void cSceneResult::Init()
{
	canGoNextScene = true;
}

void cSceneResult::Update(char* keys, char* preKeys, eScene& nextScene)
{
	if (canGoNextScene)
	{

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			nextScene = TITLE;
		}
	}
}

void cSceneResult::Draw()
{

}

void cSceneResult::DrawDebug()
{
	Novice::ScreenPrintf(12, 24, "currentScene: RESULT");
}