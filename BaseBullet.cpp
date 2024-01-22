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
	position.x = 0.0f;
	position.y = 0.0f;
	velosity.x = 0.0f;
	velosity.y = 0.0f;
	speed = 8.0f;
	radius = 32.0f;
	color = 0xffffffff;
	isActive = false;
}

void cBaseBullet::Update()
{
	
}

void cBaseBullet::Move()
{
	if (isActive)
	{
		Add(position, velosity);
	}
}

void cBaseBullet::Draw()
{
	if (isActive)
	{
		Novice::DrawEllipse(int(position.x), int(position.y), int(radius), int(radius), 0.0f, color, kFillModeSolid);
	}
}
