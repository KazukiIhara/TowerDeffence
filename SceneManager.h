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

	bool isDebug;
	eScene currentScene;
	eScene nextScene;
	eScene prevScene;
};
