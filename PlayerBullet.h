#pragma once
#include "BaseBullet.h"

class cPlayerBullet :public cBaseBullet
{
public:
	cPlayerBullet();
	~cPlayerBullet()override;
	void BulletInit(Vector2 position, Vector2 hummerPosition, float distance, int i);
	void Update()override;

private:

};