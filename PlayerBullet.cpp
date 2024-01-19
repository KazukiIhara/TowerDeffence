#include "PlayerBullet.h"

cPlayerBullet::cPlayerBullet()
{

}

cPlayerBullet::~cPlayerBullet()
{

}

void cPlayerBullet::Init(Vector2 playerPosition, Vector2 hummerPosition)
{
	position = hummerPosition;
	float len = sqrtf(playerPosition.x * hummerPosition.x + playerPosition.y * hummerPosition.y);
	velosity =
	{ (playerPosition.x - hummerPosition.x) / len * speed,
		(playerPosition.y - hummerPosition.y) / len * speed
	};
}

void cPlayerBullet::Update()
{

}
