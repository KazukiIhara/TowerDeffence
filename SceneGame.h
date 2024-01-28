#pragma once
#include "BaseScene.h"

class cPlayer;
class cEnemy;
class cEnemyManager;

class cSceneGame :public cBaseScene
{
public:
	cSceneGame();
	~cSceneGame()override;

	void Init()override;
	void Update(char* keys, char* preKeys, eScene& nextScene)override;
	void Draw()override;
	void DrawDebug()override;

private:
	int currentGameFlame;
	cPlayer* player;
	cEnemy* enemy;
	cEnemyManager* enemyManager;
};

