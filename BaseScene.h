#pragma once
#include "MyIncludes.h"

class cBaseScene
{
public:
	cBaseScene();
	virtual ~cBaseScene();

	virtual void Init();
	virtual void Update(char* keys, char* preKeys, eScene& nextScene);
	virtual void Draw();
	virtual void DrawDebug();

private:

};

