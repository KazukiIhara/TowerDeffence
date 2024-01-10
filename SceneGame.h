#pragma once

class cHammer;
class cPlayer;

class cSceneGame
{
public:
	cSceneGame();
	~cSceneGame();

	void Init();
	void Update(char* keys);
	void Draw();


private:
	cHammer* hammer;
	cPlayer* player;

};

