#pragma once
#include "Struct.h"

class cBaseScene;

class cSceneManager
{
public:
	cSceneManager();
	~cSceneManager();

	void Init();
	void SceneChange();
	void Update(char* keys, char* preKeys);
	void Draw();

private:

	cBaseScene* pCurrentScene;

	eScene currentScene;
	eScene nextScene;
	eScene prevScene;
	bool isDebug;
};
