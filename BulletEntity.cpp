//Engine52 V1.08 World Space Handler 
//BulletEntity.cpp Child of Entity class Holds Implementation of functions for Bullet entities 
#include "BulletEntity.h"



BulletEntity::BulletEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount) : Entity(TextureName, FrameWidth, FrameHeight, FrameSize, FrameCount)
{
	mAlive = false;
	mSpeed = 50;
	mHealth = 1;
	mDamage = 100;
	ResetHealth();
	
}
BulletEntity::BulletEntity() : Entity("bullet", 4, 4, 0, 0)
{
	mAlive = false;
	mSpeed = 50;
	mHealth = 1;
	mDamage = 1000;
	ResetHealth();
	
}

BulletEntity::~BulletEntity()
{
}

void BulletEntity::Update()
{
	Vector2 pos{ GetPosition() };
	if (pos.mY < 0 || pos.mY > 600 || pos.mX<0 || pos.mX>800 || mHealthLeft < 0)
	{
		mAlive = false;

	}
	
	pos.mY += mSpeed*mDirection;
	
	SetPosition(pos);
}


