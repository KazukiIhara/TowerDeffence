#include "SceneGame.h"
#include "Novice.h"
#include "Player.h"
#include "Enemy.h"

cSceneGame::cSceneGame()
{
	player = new cPlayer;
	enemy = new cEnemy;
}

cSceneGame::~cSceneGame()
{
	delete player;
	delete enemy;
}

void cSceneGame::Init()
{
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

	player->Operation(keys, preKeys);
	// プレイヤーの入力受付処理ココまで


	// マップチップのあたり判定ココから

	// マップチップのあたり判定ココまで


	// オブジェクト移動処理ココから
	player->Move();

	// オブジェクト移動処理ココまで


	// あたり判定ココから

	// あたり判定ココまで


	// 状態の更新ココから
	player->Update();
	enemy->Update();
	// 状態の更新ココまで
}

void cSceneGame::Draw()
{
	player->Draw();
	enemy->Draw();
}

void cSceneGame::DrawDebug()
{
	Novice::ScreenPrintf(int(player->GetPosition().x) + 30, int(player->GetPosition().y) - 30,
		"HP %d", player->GetHp());
}
