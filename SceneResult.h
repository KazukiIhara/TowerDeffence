#pragma once
#include "Struct.h"
#include "BaseScene.h"

class cSceneResult :public cBaseScene
{
public:
	cSceneResult();
	~cSceneResult();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

private:

};

