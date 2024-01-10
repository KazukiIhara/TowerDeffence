#pragma once
#include "Struct.h"

class cSceneGame;

class cSceneManager
{
public:
	cSceneManager();
	~cSceneManager();

	void Init();
	void Update(char* keys);
	void Draw();

private:

	cSceneGame* sceneGame;

	eScene currentScene;
	eScene nextScene;
	eScene prevScene;
};
