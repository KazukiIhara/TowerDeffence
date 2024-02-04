#pragma once
#include "MyIncludes.h"
#include "BaseScene.h"

class cSceneResult :public cBaseScene
{
public:
	cSceneResult();
	~cSceneResult();

	void Init()override;
	void Update(char* keys, char* preKeys, eScene& nextScene)override;
	void Draw()override;
	void DrawDebug()override;
	void DrawMenuTab(MenuTab tab);

private:
	bool canGoNextScene;
	MenuTab gameOver;
	MenuTab pressSpace;
};

