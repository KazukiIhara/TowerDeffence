#pragma once
#include "Struct.h"

class cPlayer
{
public:
	cPlayer();
	~cPlayer();

	void Init();
	void Operation(char *keys);
	void Update(char *keys);
	void Draw();

private:
	Vector2 position;
	float rad;

};
