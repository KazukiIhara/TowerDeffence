#pragma once
#include "MyIncludes.h"

class cBaseBullet
{
public:
	cBaseBullet();
	virtual~cBaseBullet();
	virtual void Init();
	virtual void Update();
	void Move();
	void Draw();

	//ゲッター
	bool GetIsActive(int i) { return bullet[i].isActive; }

	//セッター
	void SetIsActive(bool isActive_, int i) { bullet[i].isActive = isActive_; }
protected:
	eBullet bullet[kBulletNum];
	float speed;
	float radius;
	int color;
};

