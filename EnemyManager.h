#pragma once
#include "MyIncludes.h"

class cEnemy;
class cPlayer;
class cPlayerBullet;
class cEnemyManager
{
public:
	cEnemyManager();
	~cEnemyManager();
	void Init();
	void EnemyPop(int spawnTime_);
	void Move();
	void BulletCollision(cPlayer* player_, cPlayerBullet* bullet_, Vector2 pos_, float rad_, int i_);
	void Update();
	void Draw();

	int GetKEnemyNum() { return kEnemyNum; }

	cEnemy* GetEnemy(int i_);
private:
	static const int kEnemyNum = 30;
	cEnemy* enemy[kEnemyNum];
	int enemySpwanTimer;
};