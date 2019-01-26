//Engine52 V1.09 World Space Handler 
//ExplosionEntity.cpp Entity class Holds function Data for explosion entities
#include "ExplosionEntity.h"
#include "HAPI_lib.h"
#include "Audio.h"



ExplosionEntity::ExplosionEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount) : Entity(TextureName, FrameWidth, FrameHeight, FrameSize, FrameCount)
{
	//mDamage = 1000;
	mAlive = false;
}


ExplosionEntity::~ExplosionEntity()
{
}

void ExplosionEntity::Update()
{


	Vector2 pos{ GetPosition() };
	if (mAlive == true)
	{
		if (mTime == 5)
		{
			mTime++;
			AUDIO.PlayAudio("Explosion+3.wav");
			
		}
		if (mTime == 20)
		{
			mAlive = false;
			mTime = 5;
		}
		mTime++;
	}
	
	SetPosition(pos);
	
}
