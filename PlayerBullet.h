#pragma once
#include "BaseBullet.h"

class cPlayerBullet :public cBaseBullet
{
public:
	cPlayerBullet();
	~cPlayerBullet()override;
	void Init(Vector2 position, Vector2 hummerPosition);
	void Update()override;

private:

};

