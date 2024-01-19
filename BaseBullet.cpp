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
	speed = 4.0f;
	radius = 32.0f;
	color = 0xffffffff;
}

void cBaseBullet::Update()
{

}

void cBaseBullet::Move()
{
	Add(position, velosity);
}

void cBaseBullet::Draw()
{
	Novice::DrawEllipse(int(position.x), int(position.y), int(radius), int(radius), 0.0f, color, kFillModeSolid);
}
