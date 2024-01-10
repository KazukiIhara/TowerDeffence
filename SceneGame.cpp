#include "SceneGame.h"
#include "Hammer.h"
#include "Player.h"

cSceneGame::cSceneGame()
{
	hammer = new cHammer;
	player = new cPlayer;
}

cSceneGame::~cSceneGame()
{
	delete hammer;
	delete player;
}

void cSceneGame::Init()
{

}

void cSceneGame::Update(char* keys)
{
	player->Operation(keys);

	player->Update();
}

void cSceneGame::Draw()
{

	player->Draw();
}