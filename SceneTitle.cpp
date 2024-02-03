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
	start.size.x = 256.f;
	start.size.y = 64.0f;
	start.position.x = kScreenWidth / 2.0f;
	start.position.y = kScreenHeight / 2.0f + 300;

	start.texture = Novice::LoadTexture("./Resources/Images/title/Start.png");
	isPlayAnimation = false;
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
	Novice::DrawQuad(int(start.position.x - start.size.x / 2.0f), int(start.position.y - start.size.y / 2.0f),
		int(start.position.x + start.size.x / 2.0f), int(start.position.y - start.size.y / 2.0f),
		int(start.position.x - start.size.x / 2.0f), int(start.position.y + start.size.y / 2.0f),
		int(start.position.x + start.size.x / 2.0f), int(start.position.y + start.size.y / 2.0f),
		0, 0, int(start.size.x), int(start.size.y), start.texture, 0xffffffff);
}

void cSceneTitle::DrawDebug()
{
	Novice::ScreenPrintf(12, 24, "CurrentScene: TITLE");
}

void cSceneTitle::TitleSceneAnimation()
{
	if (isPlayAnimation)
	{

	}
}