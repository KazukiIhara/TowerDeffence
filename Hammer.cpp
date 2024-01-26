#include "Hammer.h"
#include "Novice.h"

cHammer::cHammer()
{
	Init();
}

cHammer::~cHammer()
{

}

void cHammer::Init()
{
	rad = 24.0f;
	position.x = kScreenWidth / 2.0f;
	position.y = kScreenHeight / 2.0f;
	angle = 0.0f;
}

void cHammer::Rotate(Vector2 position_,float distance,float speed)
{
	angle += speed;
	position.x = position_.x + distance * cosf(angle);
	position.y = position_.y + distance * sinf(angle);
}

void cHammer::Update()
{
	
}

void cHammer::Draw()
{
	Novice::DrawEllipse(int(position.x), int(position.y), int(rad), int(rad), 0.0f, 0xffffffff, kFillModeSolid);
}
