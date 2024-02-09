#include "Enemy.h"
#include "Novice.h"
#include <stdlib.h>
#include "Player.h"
#include "PlayerBullet.h"

cEnemy::cEnemy()
{
	Init();
}

cEnemy::~cEnemy()
{

}

void cEnemy::Init()
{
	position = { 0.0f,0.0f };
	velosity = { 0.0f,0.0f };
	rad = 32.0f;
	hp = 1;
	color = 0x000000ff;
	isActive = false;
}

void cEnemy::Pop(int direction_, int spawnPosition)
{
	rad = 32.0f;
	switch (direction_)
	{
	case 0:
		position.x = -rad;
		velosity = { 3.0f,0.0f };
		switch (spawnPosition)
		{
		case 0:
			position.y = rad * 5;
			break;
		case 1:
			position.y = rad * 10;
			break;
		case 2:
			position.y = rad * 15;
			break;
		case 3:
			position.y = rad * 20;
			break;
		case 4:
			position.y = rad * 25;
			break;
		case 5:
			position.y = rad * 30;
			break;
		default:
			break;
		}
		break;
	case 1:
		position.x = rad + kScreenWidth;
		velosity = { -3.0f,0.0f };
		switch (spawnPosition)
		{
		case 0:
			position.y = rad * 8;
			break;
		case 1:
			position.y = rad * 13;
			break;
		case 2:
			position.y = rad * 18;
			break;
		case 3:
			position.y = rad * 23;
			break;
		case 4:
			position.y = rad * 28;
			break;
		case 5:
			position.y = rad * 33;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	hp = 1;
	color = 0x000000ff;
	isActive = true;

}

void cEnemy::Damage()
{
	hp--;
}

void cEnemy::Move()
{
	Add(position, velosity);
}

void cEnemy::Update()
{

}

void cEnemy::Draw()
{
	if (isActive)
	{
		Novice::DrawEllipse(int(position.x), int(position.y),
			int(rad), int(rad),
			0.0f, color, kFillModeSolid);
	}
}

void cEnemy::BulletColliosion(cPlayer* player_, cPlayerBullet* bullet, Vector2 pos_, float rad_, int i)
{
	if (isActive)
	{
		if (bullet->GetIsActive(i))
		{
			float distance = sqrtf(powf(pos_.x - position.x, 2) + powf(pos_.y - position.y, 2));
			float radLen = rad + rad_;
			if (distance < radLen)
			{
				player_->SetScore(player_->GetScore() + 1);
				isActive = false;
				bullet->SetIsActive(false, i);
			}
		}
	}
}
