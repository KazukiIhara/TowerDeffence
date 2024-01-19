#include "Player.h"
#include "Novice.h"

cPlayer::cPlayer()
{
	Init();
}

cPlayer::~cPlayer()
{

}

void cPlayer::Init()
{
	position.x = kScreenWidth / 2.0f;
	position.y = kScreenHeight / 2.0f;
	rad = 16.0f;
	distance = 100.0f;
	speed = 0.0f;
	hp = 3;
}

void cPlayer::Operation(char* keys)
{
	if (keys[DIK_W])
	{
		position.y -= 4;
	}
	if (keys[DIK_S])
	{
		position.y += 4;
	}
	if (keys[DIK_A])
	{
		position.x -= 4;
	}
	if (keys[DIK_D])
	{
		position.x += 4;
	}

	if (keys[DIK_E])
	{
		distance += 10;
	}
	if (keys[DIK_Q])
	{
		distance -= 10;
	}
	if (Novice::IsPressMouse(0))
	{
		speed = -0.1f;
	}
	if (Novice::IsPressMouse(1))
	{
		speed = 0.1f;
	}
}

void cPlayer::Move()
{

}

void cPlayer::Update()
{

}

void cPlayer::Draw()
{
	Novice::DrawEllipse(int(position.x), int(position.y), int(rad), int(rad), 0.0f, 0xffffffff, kFillModeSolid);
}

void cPlayer::DrawLine(Vector2 pos_)
{
	Novice::DrawLine(int(position.x), int(position.y), int(pos_.x), int(pos_.y), 0xffffffff);
}
