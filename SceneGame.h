#pragma once
#include "BaseScene.h"

class cPlayer;
class cEnemyManager;
class cGameUI;

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
	int flameTimer;
	int currentGameSecond;
	int currentLevel;
	cPlayer* player;
	cEnemyManager* enemyManager;
	cGameUI* UI;
};

