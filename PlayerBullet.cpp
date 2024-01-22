#include "PlayerBullet.h"

cPlayerBullet::cPlayerBullet()
{
	Init();
}

cPlayerBullet::~cPlayerBullet()
{

}

void cPlayerBullet::BulletInit(Vector2 playerPosition, Vector2 hummerPosition, float distance)
{
	position = hummerPosition;
	velosity.x = (hummerPosition.x - playerPosition.x) / distance * speed;
	velosity.y = (hummerPosition.y - playerPosition.y) / distance * speed;
}

void cPlayerBullet::Update()
{
	if (position.x - radius > kScreenWidth || position.x + radius < 0.0f ||
		position.y + radius < 0.0f || position.y - radius > kScreenHeight)
	{
		isActive = false;
	}
}
