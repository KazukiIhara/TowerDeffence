#pragma once

class cHammer;
class cPlayer;
class cEnemy;

class cSceneGame
{
public:
	cSceneGame();
	~cSceneGame();

	void Init();
	void Update(char* keys, char* preKeys);
	void Draw();
	void DrawDebug();

private:
	cHammer* hammer;
	cPlayer* player;
	cEnemy* enemy;
};

