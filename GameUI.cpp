#include "GameUI.h"
#include "Novice.h"

cGameUI::cGameUI()
{
	Init();
}

cGameUI::~cGameUI()
{

}

void cGameUI::Init()
{
	MoveUI.size.x = 512.0f;
	MoveUI.size.y = 64.0f;
	MoveUI.position.x = 256.0f;
	MoveUI.position.y = kScreenHeight - MoveUI.size.y;
	MoveUI.texture = Novice::LoadTexture("./Resources/Images/Game/UI/Move.png");

	ShotUI.size.x = 512.0f;
	ShotUI.size.y = 64.0f;
	ShotUI.position.x = 768.0f;
	ShotUI.position.y = kScreenHeight - ShotUI.size.y;
	ShotUI.texture = Novice::LoadTexture("./Resources/Images/Game/UI/Shot.png");

}

void cGameUI::Draw()
{
	DrawMenuTab(MoveUI);
	DrawMenuTab(ShotUI);
}

void cGameUI::DrawMenuTab(MenuTab tab)
{
	Novice::DrawQuad(int(tab.position.x - tab.size.x / 2.0f), int(tab.position.y - tab.size.y / 2.0f),
		int(tab.position.x + tab.size.x / 2.0f), int(tab.position.y - tab.size.y / 2.0f),
		int(tab.position.x - tab.size.x / 2.0f), int(tab.position.y + tab.size.y / 2.0f),
		int(tab.position.x + tab.size.x / 2.0f), int(tab.position.y + tab.size.y / 2.0f),
		0, 0, int(tab.size.x), int(tab.size.y), tab.texture, 0xffffffff);

}
