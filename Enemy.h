#pragma once
#include "Struct.h"

class cEnemy
{
public:
	cEnemy();
	~cEnemy();

	void Init();
	void Update();
	void Draw();


private:
	Vector2 position;
	float rad;
	int hp;
	int color;
};

