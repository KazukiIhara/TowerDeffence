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
protected:
	Vector2 position;
	Vector2 velosity;
	float speed;
	float radius;
	int color;
};

