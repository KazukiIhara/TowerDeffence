#pragma once
#include "MyIncludes.h"

class cBaseParticle
{
public:
	cBaseParticle();
	~cBaseParticle();
	void Init();
	void Emit();
	void Move();
	void Update();
	void Draw();

private:
	Particle particle[kParticleNum];
};