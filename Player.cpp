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
	position.x = kWorldWidth / 2.0f;
	position.y = kWorldHeight / 2.0f;
	rad = 32.0f;
}

void cPlayer::Update()
{

}

void cPlayer::Draw()
{
	Novice::DrawEllipse(int(position.x), int(position.y), int(rad), int(rad), 0.0f, 0xffffffff, kFillModeSolid);
}
