#pragma once
#include "Struct.h"

class cPlayer
{
public:
	cPlayer();
	~cPlayer();

	void Init();
	void Update();
	void Draw();

private:
	Vector2 position;
	float rad;

};
