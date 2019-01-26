//Engine52 V1.09 World Space Handler 
//EnemyEntity.cpp class Holds Function Data for Enemy entities
#include "EnemyEntity.h"
#include "Audio.h"
#include <random>
#include <time.h>
#include "world.h"



EnemyEntity::EnemyEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount) : Entity(TextureName, FrameWidth, FrameHeight, FrameSize, FrameCount)
{
	mHealth = 200;
	mDamage = 10;
	mSpeed = ((float)(rand() % 5 + 2));
	ResetHealth();
	mZ = (float)(rand() % 200 + 30);
	GetNewCont(2);
	
}


EnemyEntity::~EnemyEntity()
{
}

void EnemyEntity::Update()
{
    float x = (float)(rand() % 725 + 50);
	float y = -(float) (rand() % 350 + 20);
	
	Vector2 pos{ GetPosition() };
	

	mDirection = 1;
	if (mHealthLeft <= 0)
	{
		
		AUDIO.PlayAudio("Recording.wav");
		WORLD.SpawnExplosion(pos);
		mAlive = false;
		WORLD.KillEnemy();
		WORLD.SetScore(mPoints);
		pos.mX = x;
		pos.mY = y;
		SetPosition(pos);
		mAlive = true;
		ResetHealth();
		mSpeed = ((float)(rand() % 5 + 2));
			

	}
	pos.mY += mSpeed;
	
	SetPosition(pos);
	mBulletSpawn = pos;
	mBulletSpawn.mX += 10;
	mBulletSpawn.mY += 60;
	if (pos.mY > 320)
	{
		mSpeed = 0;
		mTime++;
		if (mTime >= mZ)
		{
			
			WORLD.FireBullet(mBulletSpawn, mDirection, 2);
			AUDIO.PlayAudio("gunShot.wav");
			mZ = (float)(rand() % 200 + 30);
			mTime = 0;
		}
	}
	
	
	
}
