#pragma once
#include "Struct.h"

class cEnemy
{
public:
	cEnemy();
	~cEnemy();

	void Init();
	void Damage();
	void Update();
	void Draw();

	//�Q�b�^�[////////////////////////
	Vector2 GetPosition() { return position; }
	int GetHp() { return hp; }

	//�Z�b�^�[////////////////////////
	void SetPosition(Vector2 position_) { position = position_; }
	void SetHp(int hp_) { hp = hp_; }

private:
	Vector2 position;
	float rad;
	int hp;
	int color;
};

