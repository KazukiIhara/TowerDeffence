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
	rad = 64.0f;
	position.x = kWorldWidth / 2.0f;
	position.y = kWorldHeight / 2.0f;
}

void cHammer::Update()
{
	
}

void cHammer::Draw()
{
	Novice::DrawEllipse(int(position.x), int(position.y), int(rad), int(rad), 0.0f, 0xffffffff, kFillModeSolid);
}
