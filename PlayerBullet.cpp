#include "PlayerBullet.h"

cPlayerBullet::cPlayerBullet()
{
	Init();
}

cPlayerBullet::~cPlayerBullet()
{

}

void cPlayerBullet::BulletInit(Vector2 playerPosition, Vector2 hummerPosition, float distance, int i)
{
	bullet[i].position = hummerPosition;
	bullet[i].velosity.x = (hummerPosition.x - playerPosition.x) / distance * speed;
	bullet[i].velosity.y = (hummerPosition.y - playerPosition.y) / distance * speed;
}

void cPlayerBullet::Update()
{
	for (int i = 0; i < kBulletNum; i++)
	{
		if (bullet[i].position.x - radius > kScreenWidth || bullet[i].position.x + radius < 0.0f ||
			bullet[i].position.y + radius < 0.0f || bullet[i].position.y - radius > kScreenHeight)
		{
			bullet[i].isActive = false;
		}
	}
}
