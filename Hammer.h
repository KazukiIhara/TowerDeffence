#pragma once
#include "Struct.h"

class cHammer
{
public:
	cHammer();
	~cHammer();

	void Init();
	void Update();
	void Draw();

private:
	Vector2 position;
	float rad;

};


