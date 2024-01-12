#pragma once
#include "BaseScene.h"

class cHammer;
class cPlayer;
class cEnemy;

class cSceneGame :public cBaseScene
{
public:
	cSceneGame();
	~cSceneGame()override;

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
	void DrawDebug()override;

private:
	cHammer* hammer;
	cPlayer* player;
	cEnemy* enemy;
};

