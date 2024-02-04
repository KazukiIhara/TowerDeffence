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
	start.position.y = kScreenHeight / 2.0f + 250;
	start.texture = Novice::LoadTexture("./Resources/Images/title/Start.png");

	pressSpace.size.x = 512.0f;
	pressSpace.size.y = 64.0f;
	pressSpace.position.x = kScreenWidth / 2.0f;
	pressSpace.position.y = kScreenHeight / 2.0f + 300;
	pressSpace.texture = Novice::LoadTexture("./Resources/Images/title/PressSpace.png");

	exitTab.size.x = 256.0f;
	exitTab.size.y = 64.0f;
	exitTab.position.x = kScreenWidth / 2.0f;
	exitTab.position.y = kScreenHeight / 2.0f + 350;
	exitTab.texture = Novice::LoadTexture("./Resources/Images/title/Exit.png");

	isMainMenu = false;
	isPlayAnimation = false;
	selectMenu = GAMESTART;
}

void cSceneTitle::Update(char* keys, char* preKeys, eScene& nextScene)
{
	if (isMainMenu)
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
	else
	{
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			isMainMenu = true;
		}
	}
}

void cSceneTitle::Draw()
{
	if (!isMainMenu)
	{
		DrawMenuTab(pressSpace);
	}
	else
	{
		DrawMenuTab(start);
		DrawMenuTab(exitTab);
		switch (selectMenu)
		{
		case 0:
			Novice::DrawBox(int(start.position.x - start.size.x / 2.0f), int(start.position.y - start.size.y / 2.0f), int(start.size.x), int(start.size.y), 0.0f, 0xffffffff, kFillModeWireFrame);
			break;

		case 1:
			Novice::DrawBox(int(exitTab.position.x - exitTab.size.x / 2.0f), int(exitTab.position.y - exitTab.size.y / 2.0f), int(exitTab.size.x), int(exitTab.size.y), 0.0f, 0xffffffff, kFillModeWireFrame);
			break;
		default:
			break;
		}

	}
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

void cSceneTitle::DrawMenuTab(MenuTab tab)
{
	Novice::DrawQuad(int(tab.position.x - tab.size.x / 2.0f), int(tab.position.y - tab.size.y / 2.0f),
		int(tab.position.x + tab.size.x / 2.0f), int(tab.position.y - tab.size.y / 2.0f),
		int(tab.position.x - tab.size.x / 2.0f), int(tab.position.y + tab.size.y / 2.0f),
		int(tab.position.x + tab.size.x / 2.0f), int(tab.position.y + tab.size.y / 2.0f),
		0, 0, int(tab.size.x), int(tab.size.y), tab.texture, 0xffffffff);

}
