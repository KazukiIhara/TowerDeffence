#pragma once
#include "MyIncludes.h"

class cBaseBullet
{
public:
	cBaseBullet();
	~cBaseBullet();
	virtual void Init();
	virtual void Update();
	void Move();
	void Draw();
private:
	Vector2 position;
	Vector2 velosity;
	float radius;
	int color;
};

