#include "BaseBullet.h"
#include <Novice.h>

cBaseBullet::cBaseBullet()
{
	Init();
}

cBaseBullet::~cBaseBullet()
{

}

void cBaseBullet::Init()
{
	for (int i = 0; i < kBulletNum; i++)
	{
		bullet[i].position.x = 0.0f;
		bullet[i].position.y = 0.0f;
		bullet[i].velosity.x = 0.0f;
		bullet[i].velosity.y = 0.0f;
		bullet[i].isActive = false;
	}
	speed = 8.0f;
	radius = 16.0f;
	color = 0xffffffff;
}

void cBaseBullet::Update()
{

}

void cBaseBullet::Move()
{
	for (int i = 0; i < kBulletNum; i++)
	{
		if (bullet[i].isActive)
		{
			Add(bullet[i].position, bullet[i].velosity);
		}
	}
}

void cBaseBullet::Draw()
{
	for (int i = 0; i < kBulletNum; i++)
	{
		if (bullet[i].isActive)
		{
			Novice::DrawEllipse(int(bullet[i].position.x), int(bullet[i].position.y), int(radius), int(radius), 0.0f, color, kFillModeSolid);
		}
	}
}
