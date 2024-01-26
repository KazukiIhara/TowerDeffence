#include "Enemy.h"
#include "Novice.h"
#include <stdlib.h>
#include "PlayerBullet.h"

cEnemy::cEnemy()
{
	Init(LEFT, 0);
}

cEnemy::~cEnemy()
{

}

void cEnemy::Init(eDirection direction_, int spwanPosition)
{
	rad = 32.0f;
	switch (direction_)
	{
	case LEFT:
		position.x = -rad;
		velosity = { 3.0f,0.0f };
		break;
	case RIGHT:
		position.x = rad;
		velosity = { -3.0f,0.0f };
		break;
	default:
		break;
	}
	switch (spwanPosition)
	{
	case 0:
		position.y = rad;
		break;
	case 1:
		position.y = rad * 2;
		break;
	case 2:
		position.y = rad * 3;
		break;
	case 3:
		position.y = rad * 4;
		break;
	case 4:
		position.y = rad * 5;
		break;
	case 5:
		position.y = rad * 6;
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

void cEnemy::BulletColliosion(cPlayerBullet* bullet, Vector2 pos_, float rad_, int i)
{
	if (isActive)
	{
		if (bullet->GetIsActive(i))
		{
			float distance = sqrtf(powf(pos_.x - position.x, 2) + powf(pos_.y - position.y, 2));
			float radLen = rad + rad_;
			if (distance <= radLen)
			{
				isActive = false;
				bullet->SetIsActive(false, i);
			}
		}
	}
}
