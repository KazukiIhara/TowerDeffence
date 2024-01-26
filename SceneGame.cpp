#include "SceneGame.h"
#include "Novice.h"
#include "Player.h"
#include "EnemyManager.h"

cSceneGame::cSceneGame()
{
	player = new cPlayer;
	enemyManager = new cEnemyManager;
	Init();
}

cSceneGame::~cSceneGame()
{
	delete player;
	delete enemyManager;
}

void cSceneGame::Init()
{
	currentGameFlame = 0;
	player->Init();
	enemyManager->Init();
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

	enemyManager->EnemyPop();

	// マップチップのあたり判定ココから

	// マップチップのあたり判定ココまで


	// オブジェクト移動処理ココから
	player->Move();
	enemyManager->Move();
	// オブジェクト移動処理ココまで


	// あたり判定ココから
	for (int i = 0; i < kBulletNum; i++)
	{
		enemyManager->BulletCollision(player->GetBulletP(), player->GetBulletPosition(i), player->GetBulletRadius(), i);
	}
	// あたり判定ココまで


	// 状態の更新ココから
	player->Update();
	enemyManager->Update();
	// 状態の更新ココまで
}

void cSceneGame::Draw()
{
	player->Draw();
	enemyManager->Draw();
}

void cSceneGame::DrawDebug()
{
	Novice::ScreenPrintf(int(player->GetPosition().x) + 30, int(player->GetPosition().y) - 30,
		"HP %d", player->GetHp());
}
