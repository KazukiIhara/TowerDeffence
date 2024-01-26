#pragma once
#include "MyIncludes.h"

class cEnemy;
class cPlayerBullet;
class cEnemyManager
{
public:
	cEnemyManager();
	~cEnemyManager();
	void Init();
	void EnemyPop();
	void Move();
	void BulletCollision(cPlayerBullet* bullet_, Vector2 pos_, float rad_, int i_);
	void Update();
	void Draw();

private:
	static const int kEnemyNum = 30;
	cEnemy* enemy[kEnemyNum];
	int enemySpwanTimer;
};