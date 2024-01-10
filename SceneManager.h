#pragma once
#include "Struct.h"

class cSceneGame;

class cSceneManager
{
public:
	cSceneManager();
	~cSceneManager();

	void Init();
	void Update(char* keys, char* preKeys);
	void Draw();

private:

	cSceneGame* sceneGame;

	eScene currentScene;
	eScene nextScene;
	eScene prevScene;
	bool isDebug;
};
