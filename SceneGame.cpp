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
	flameTimer = 0;
	currentGameSecond = 0;
	currentLevel = HARD;
	player->Init();
	enemyManager->Init();
}

void cSceneGame::Update(char* keys, char* preKeys, eScene& nextScene)
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
	switch (currentLevel)
	{
	case EASY:
		enemyManager->EnemyPop(kEnemySpwanTime + 60);
		break;
	case NOMAL:
		enemyManager->EnemyPop(kEnemySpwanTime);
		break;
	case HARD:
		enemyManager->EnemyPop(kEnemySpwanTime - 120);
		break;
	default:
		break;
	}

	// マップチップのあたり判定ココから

	// マップチップのあたり判定ココまで


	// オブジェクト移動処理ココから
	player->Move();
	enemyManager->Move();
	// オブジェクト移動処理ココまで


	// あたり判定ココから
	for (int i = 0; i < enemyManager->GetKEnemyNum(); i++)
	{
		player->EnemyCollision(enemyManager, i);
	}
	for (int i = 0; i < kBulletNum; i++)
	{
		enemyManager->BulletCollision(player, player->GetBulletP(), player->GetBulletPosition(i), player->GetBulletRadius(), i);
	}
	// あたり判定ココまで


	// 状態の更新ココから
	player->Update(nextScene);
	enemyManager->Update();
	flameTimer++;
	if (flameTimer % 60 == 0)
	{
		currentGameSecond++;
		flameTimer = 0;
	}
	// 状態の更新ココまで
}

void cSceneGame::Draw()
{
	player->Draw();
	enemyManager->Draw();
}

void cSceneGame::DrawDebug()
{
	Novice::ScreenPrintf(int(player->GetPosition().x) + 30, int(player->GetPosition().y) - 30, "HP %d", player->GetHp());
	Novice::ScreenPrintf(12, 24, "CurrentScene: GAME");
	Novice::ScreenPrintf(12, 24 * 2, "CurrentGameSecond: %d", currentGameSecond);
	Novice::ScreenPrintf(12, 24 * 3, "Score: %d", player->GetScore());
	switch (currentLevel)
	{
	case EASY:
		Novice::ScreenPrintf(12, 24 * 4, "Level: EASY");
		break;
	case NOMAL:
		Novice::ScreenPrintf(12, 24 * 4, "Level: NOMAL");
		break;
	case HARD:
		Novice::ScreenPrintf(12, 24 * 4, "Level: HARD");
		break;
	default:
		break;
	}
}
