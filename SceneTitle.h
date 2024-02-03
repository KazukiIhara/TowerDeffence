#pragma once
#include "MyIncludes.h"
#include "BaseScene.h"

class cSceneTitle :public cBaseScene
{
public:
	cSceneTitle();
	~cSceneTitle()override;
	void Init()override;
	void Update(char* keys, char* preKeys, eScene& nextScene)override;
	void Draw()override;
	void DrawDebug()override;
	void TitleSceneAnimation();

private:
	int selectMenu;

	/*Startメニュー*/
	MenuTab start;

	bool isPlayAnimation;
};

