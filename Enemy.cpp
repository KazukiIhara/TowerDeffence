#include "Enemy.h"
#include "Novice.h"
#include <stdlib.h>
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
	position.x = 0.0f;
	position.y = float(rand() % 1080);
	rad = 32.0f;
	hp = 1;
	color = 0x000000ff;
	isActive = true;
}

void cEnemy::Damage()
{
	hp--;
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
