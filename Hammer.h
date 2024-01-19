#pragma once
#include "MyIncludes.h"

class cHammer
{
public:
	cHammer();
	~cHammer();

	void Init();
	void Rotate(Vector2 position_, float distance, float speed);
	void Update();
	void Draw();


	//ゲッター////////////////////////
	Vector2 GetPosition() { return position; }

	//セッター////////////////////////
	void SetPosition(Vector2 position_) { position = position_; }
private:
	Vector2 position;
	float rad;
	float angle;

};


