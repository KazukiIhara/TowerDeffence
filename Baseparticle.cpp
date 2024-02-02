#include "BaseParticle.h"
#include <Novice.h>


cBaseParticle::cBaseParticle()
{
	Init();
}

cBaseParticle::~cBaseParticle()
{

}

void cBaseParticle::Init()
{
	for (int i = 0; i < kParticleNum; i++)
	{
		particle[i].position = { 0.0f,0.0f };
		particle[i].size = { 16.0f,16.0f };
		particle[i].theta = 0.0f;
		particle[i].velosity = { 0.0f,0.0f };
		particle[i].isActive = false;
	}
}

void cBaseParticle::Emit()
{

}

void cBaseParticle::Move()
{
	
}

void cBaseParticle::Update()
{

}

void cBaseParticle::Draw()
{

}