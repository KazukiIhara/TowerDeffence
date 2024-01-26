#include "Player.h"
#include "Novice.h"
#include "PlayerBullet.h"
#include "Hammer.h"

cPlayer::cPlayer()
{
	bullet = new cPlayerBullet;
	hammer = new cHammer;
	Init();
}

cPlayer::~cPlayer()
{
	delete hammer;
	delete bullet;
}

void cPlayer::Init()
{
	hammer->Init();
	bullet->Init();
	position.x = kScreenWidth / 2.0f;
	position.y = kScreenHeight / 2.0f;
	velosity.x = 0.0f;
	velosity.y = 0.0f;
	rad = 16.0f;
	distance = 100.0f;
	speed = 0.1f;
	hp = 3;
}

void cPlayer::Operation(char* keys, char* preKeys)
{
	if (keys[DIK_W])
	{
		velosity.y -= 3;
	}
	if (keys[DIK_S])
	{
		velosity.y += 3;
	}
	if (keys[DIK_A])
	{
		velosity.x -= 3;
	}
	if (keys[DIK_D])
	{
		velosity.x += 3;
	}

	if (keys[DIK_E])
	{
		distance += 10;
	}
	if (keys[DIK_Q])
	{
		distance -= 10;
	}
	BulletShot(keys, preKeys);
}

void cPlayer::Move()
{
	Add(position, velosity);
	hammer->Rotate(position, distance, speed);
	bullet->Move();
}

void cPlayer::Update()
{
	velosity = { 0.0f,0.0f };
	hammer->Update();
	bullet->Update();
}

void cPlayer::Draw()
{
	DrawLine(hammer->GetPosition());
	Novice::DrawEllipse(int(position.x), int(position.y), int(rad), int(rad), 0.0f, 0xffffffff, kFillModeSolid);
	hammer->Draw();
	bullet->Draw();
}

void cPlayer::DrawLine(Vector2 pos_)
{
	Novice::DrawLine(int(position.x), int(position.y), int(pos_.x), int(pos_.y), 0xffffffff);
}

void cPlayer::BulletShot(char* keys, char* preKeys)
{
	for (int i = 0; i < kBulletNum; i++)
	{
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet->GetIsActive(i))
		{
			bullet->SetIsActive(true, i);
			speed *= -1.0f;
			bullet->BulletInit(position, hammer->GetPosition(), distance, i);
			break;
		}
	}
}

Vector2 cPlayer::GetBulletPosition(int i) { return bullet->GetPosition(i); }

float cPlayer::GetBulletRadius() { return bullet->GetRadius(); }

cPlayerBullet* cPlayer::GetBulletP() { return bullet; }
