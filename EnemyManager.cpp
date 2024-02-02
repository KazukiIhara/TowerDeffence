#include "EnemyManager.h"
#include "Enemy.h"
#include "PlayerBullet.h"

cEnemyManager::cEnemyManager()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i] = new cEnemy;
	}
	Init();
}

cEnemyManager::~cEnemyManager()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		delete enemy[i];
	}
}

void cEnemyManager::Init()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i]->Init();
	}
	enemySpwanTimer = 0;
}

void cEnemyManager::EnemyPop()
{
	if (!enemySpwanTimer)
	{
		enemySpwanTimer = kEnemySpwanTime;
		for (int i = 0; i < kEnemyNum; i++)
		{
			if (!enemy[i]->GetIsActive())
			{
				enemy[i]->Pop(rand() % 2, rand() % 5);
				break;
			}
		}
	}
}

void cEnemyManager::Move()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i]->Move();
	}
}

void cEnemyManager::BulletCollision(cPlayerBullet* bullet_, Vector2 pos_, float rad_, int i_)
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i]->BulletColliosion(bullet_, pos_, rad_, i_);
	}
}

void cEnemyManager::Update()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i]->Update();
	}
	enemySpwanTimer--;
}

void cEnemyManager::Draw()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i]->Draw();
	}
}

cEnemy* cEnemyManager::GetEnemy(int i_) { return enemy[i_]; }
