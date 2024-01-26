#pragma once
#include "MyIncludes.h"
#include "BaseScene.h"

class cSceneTitle :public cBaseScene
{
public:
	cSceneTitle();
	~cSceneTitle()override;

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

private:

};

