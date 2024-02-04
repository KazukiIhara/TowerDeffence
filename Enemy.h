#pragma once
#include "MyIncludes.h"

class cPlayer;
class cPlayerBullet;
class cEnemy
{
public:
	cEnemy();
	~cEnemy();

	void Init();
	void Pop(int direction_, int spwanPosition);
	void Damage();
	void Move();
	void Update();
	void Draw();

	void BulletColliosion(cPlayer* player_, cPlayerBullet* bullet, Vector2 pos_, float rad_, int i);

	//ゲッター////////////////////////
	Vector2 GetPosition() { return position; }
	int GetHp() { return hp; }
	bool GetIsActive() { return isActive; }
	float GetRad() { return rad; }

	//セッター////////////////////////
	void SetPosition(Vector2 position_) { position = position_; }
	void SetHp(int hp_) { hp = hp_; }

private:
	Vector2 position;
	Vector2 velosity;
	float rad;
	int hp;
	int color;
	bool isActive;
};