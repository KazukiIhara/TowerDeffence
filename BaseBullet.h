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
	Vector2 GetPosition(int i) { return bullet[i].position; }
	float GetRadius() { return radius; }

	//セッター
	void SetIsActive(bool isActive_, int i) { bullet[i].isActive = isActive_; }
protected:
	eBullet bullet[kBulletNum];
	float speed;
	float radius;
	int color;
};

