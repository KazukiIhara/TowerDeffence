#include "SceneGame.h"
#include "Hammer.h"
#include "Player.h"
#include "Novice.h"

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
	player->Init();
	hammer->Init();
}

void cSceneGame::Update(char* keys, char* preKeys)
{
	if (keys[DIK_R] && !preKeys[DIK_R])
	{
		Init();
	}
	if (keys[DIK_0])
	{
		int a;
		a = 0;
	}
	// プレイヤーの入力受付処理ココから

	player->Operation(keys);
	// プレイヤーの入力受付処理ココまで


	// マップチップのあたり判定ココから

	// マップチップのあたり判定ココまで


	// オブジェクト移動処理ココから
	player->Move();
	hammer->Rotate(player->GetPosition(), player->GetDistance(), player->GetSpeed());

	// オブジェクト移動処理ココまで


	// あたり判定ココから

	// あたり判定ココまで


	// 状態の更新ココから
	player->Update();
	hammer->Update();
	// 状態の更新ココまで
}

void cSceneGame::Draw()
{
	player->DrawLine(hammer->GetPosition());
	player->Draw();
	hammer->Draw();
}