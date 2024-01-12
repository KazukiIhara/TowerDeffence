#pragma once
#include "Struct.h"

class cPlayer
{
public:
	cPlayer();
	~cPlayer();

	void Init();
	void Operation(char* keys);
	void Move();
	void Update();
	void Draw();
	void DrawLine(Vector2 pos_);

	//ゲッター////////////////////////
	Vector2 GetPosition() { return position; }
	float GetDistance() { return distance; }
	float GetSpeed() { return speed; }
	int GetHp() { return hp; }

	//セッター////////////////////////
	void SetPosition(Vector2 position_) { position = position_; }
	void SetDistance(float distance_) { distance = distance_; }

private:
	Vector2 position;
	float rad;
	float distance;
	float speed;
	int hp;
};
