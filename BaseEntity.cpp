//Engine52 V1.09 World Space Handler 
//BaseEntity.h Child of Entity class Holds Implementation of functions for Base entities 
#include "BaseEntity.h"
#include "world.h"

BaseEntity::BaseEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount) : Entity(TextureName, FrameWidth, FrameHeight, FrameSize, FrameCount)
{
	mHealth = 1000;
	ResetHealth();
	GetNewCont(1);
}

BaseEntity::~BaseEntity()
{
}

void BaseEntity::Update()
{
	Vector2 pos{ GetPosition() };
	if (mHealthLeft <= 0)
	{
		WORLD.SpawnExplosion(Vector2 (pos.mX + 50, pos.mY + 150));
		mAlive = false;
		WORLD.KillBase();
		WORLD.SetScore(mPoints);
	}
	SetPosition(pos);
	
}
