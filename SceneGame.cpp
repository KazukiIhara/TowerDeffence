#include "SceneGame.h"
#include "Novice.h"
#include "Hammer.h"
#include "Player.h"
#include "Enemy.h"

cSceneGame::cSceneGame()
{
	hammer = new cHammer;
	player = new cPlayer;
	enemy = new cEnemy;
}

cSceneGame::~cSceneGame()
{
	delete hammer;
	delete player;
	delete enemy;
}

void cSceneGame::Init()
{
	hammer->Init();
	player->Init();
	enemy->Init();
}

void cSceneGame::Update(char* keys, char* preKeys)
{
	//　リセット
	if (keys[DIK_R] && !preKeys[DIK_R])
	{
		Init();
	}
	// デバッグ用
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
	enemy->Update();
	// 状態の更新ココまで
}

void cSceneGame::Draw()
{
	player->DrawLine(hammer->GetPosition());
	player->Draw();
	enemy->Draw();
	hammer->Draw();
}

void cSceneGame::DrawDebug()
{
	Novice::ScreenPrintf(int(player->GetPosition().x)+30, int(player->GetPosition().y)-30,
		"HP %d", player->GetHp());
}
