#pragma once
#pragma once
#include "MyIncludes.h"

class cHammer;
class cPlayerBullet;
class cPlayer
{
public:
	cPlayer();
	~cPlayer();

	void Init();
	void Operation(char* keys, char* preKeys);
	void Move();
	void Update(eScene& nextScene);
	void Draw();
	void DrawLine(Vector2 pos_);
	void BulletShot(char* keys, char* preKeys);

	//ゲッター////////////////////////
	Vector2 GetPosition() { return position; }
	float GetDistance() { return distance; }
	float GetSpeed() { return speed; }
	int GetHp() { return hp; }
	Vector2 GetBulletPosition(int i);
	float GetBulletRadius();
	cPlayerBullet* GetBulletP();

	//セッター////////////////////////
	void SetPosition(Vector2 position_) { position = position_; }
	void SetDistance(float distance_) { distance = distance_; }

private:
	cHammer* hammer;
	cPlayerBullet* bullet;
	Vector2 position;
	Vector2 velosity;
	float rad;
	float distance;
	float speed;
	int hp;
	bool isActive;
};
