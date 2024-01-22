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
	bool GetIsActive() { return isActive; }

	//セッター
	void SetIsActive(bool isActive_) { isActive = isActive_; }
protected:
	Vector2 position;
	Vector2 velosity;
	float speed;
	float radius;
	int color;
	bool isActive;
};

