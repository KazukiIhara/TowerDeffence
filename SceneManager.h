#pragma once
#include "Struct.h"

class cSceneManager
{
public:
	cSceneManager();
	~cSceneManager();

	void Init();
	void Update();
	void Draw();

private:
	eScene currentScene;
	eScene nextScene;
	eScene prevScene;
};
