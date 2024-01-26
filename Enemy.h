#pragma once
#include "MyIncludes.h"

class cPlayerBullet;
class cEnemy
{
public:
	cEnemy();
	~cEnemy();

	void Init();
	void Damage();
	void Update();
	void Draw();

	void BulletColliosion(cPlayerBullet* bullet, Vector2 pos_, float rad_, int i);

	//ゲッター////////////////////////
	Vector2 GetPosition() { return position; }
	int GetHp() { return hp; }

	//セッター////////////////////////
	void SetPosition(Vector2 position_) { position = position_; }
	void SetHp(int hp_) { hp = hp_; }

private:
	Vector2 position;
	float rad;
	int hp;
	int color;
	bool isActive;
};

