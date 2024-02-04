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
	gameOver.size.x = 1024.0f;
	gameOver.size.y = 128.0f;
	gameOver.position.x = kScreenWidth / 2.0f;
	gameOver.position.y = kScreenHeight / 2.0f - 50.0f;
	gameOver.texture = Novice::LoadTexture("./Resources/Images/Result/GameOver.png");

	pressSpace.size.x = 512.0f;
	pressSpace.size.y = 64.0f;
	pressSpace.position.x = kScreenWidth / 2.0f;
	pressSpace.position.y = kScreenHeight / 2.0f + 300;
	pressSpace.texture = Novice::LoadTexture("./Resources/Images/title/PressSpace.png");

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
	DrawMenuTab(gameOver);
	DrawMenuTab(pressSpace);
}

void cSceneResult::DrawDebug()
{
	Novice::ScreenPrintf(12, 24, "CurrentScene: RESULT");
}

void cSceneResult::DrawMenuTab(MenuTab tab)
{
	Novice::DrawQuad(int(tab.position.x - tab.size.x / 2.0f), int(tab.position.y - tab.size.y / 2.0f),
		int(tab.position.x + tab.size.x / 2.0f), int(tab.position.y - tab.size.y / 2.0f),
		int(tab.position.x - tab.size.x / 2.0f), int(tab.position.y + tab.size.y / 2.0f),
		int(tab.position.x + tab.size.x / 2.0f), int(tab.position.y + tab.size.y / 2.0f),
		0, 0, int(tab.size.x), int(tab.size.y), tab.texture, 0xffffffff);

}
