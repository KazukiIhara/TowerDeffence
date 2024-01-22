#include "Enemy.h"
#include "Novice.h"
#include <stdlib.h>

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
	Novice::DrawEllipse(int(position.x), int(position.y),
		int(rad), int(rad),
		0.0f, color, kFillModeSolid);
}
