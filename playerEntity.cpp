//Engine52 V1.09 World Space Handler 
//PlayerEntity.cpp Entity class Holds member Data for player entities
#include "playerEntity.h"
#include "HAPI_lib.h"
#include "world.h"
#include "Audio.h"

using namespace HAPISPACE;



playerEntity::playerEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount) : Entity(TextureName, FrameWidth, FrameHeight, FrameSize, FrameCount)
{
	mHealth = 300;
	mDamage = 50;
	ResetHealth();
	GetNewCont(1);
}


playerEntity::~playerEntity()
{
}

void playerEntity::Update()
{
	if (mHealthLeft <= 0)
	{
		mAlive = false;
		WORLD.KillPlayer();
		SetPosition(Vector2(374, 530));
		ResetHealth();
		mAlive = true;
	}
		

	

	Vector2 pos{ GetPosition() };
	mBulletSpawn = pos;
	mBulletSpawn.mX += 28;
	
	const HAPI_TKeyboardData& r_key_data = HAPI.GetKeyboardData();
	if (r_key_data.scanCode[HK_UP])
	{
		if (pos.mY>400)
		pos.mY -= mSpeed;
	}
		
	if (r_key_data.scanCode[HK_DOWN])
	{
		if (pos.mY<490)
		pos.mY += mSpeed;
	}
		
	if (r_key_data.scanCode[HK_LEFT])
	{
		if (!(pos.mX < 250 && pos.mY > 490))
		pos.mX -= mSpeed;
	}
	if (r_key_data.scanCode[HK_RIGHT])
	{
		if (!(pos.mX > 500 && pos.mY > 490))
		pos.mX += mSpeed;
    }
		
	if (r_key_data.scanCode[HK_SPACE])
	{
		mTime++;
		if (mTime >= 5)
		{
			WORLD.FireBullet(mBulletSpawn, mDirection, 1);
			AUDIO.PlayAudio("gunShot.wav");
			mTime = 0;
		}
	}
	if (r_key_data.scanCode[HK_ESCAPE])
	{
		HAPI.Close();
	}
		
	const HAPI_TControllerData& r_data = HAPI.GetControllerData(0);
	if (r_data.isAttached)
	{
		if (r_data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			if (!(pos.mX < 250 && pos.mY > 490))
				pos.mX -= mSpeed;
		}
		if (r_data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			if (!(pos.mX > 500 && pos.mY > 490))
				pos.mX += mSpeed;
		}
		if (r_data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			if (pos.mY < 490)
				pos.mY+= mSpeed;
		}
		if (r_data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			if (pos.mY > 400)
				pos.mY -= mSpeed;
		}
		if (r_data.analogueButtons[HK_ANALOGUE_RIGHT_TRIGGER])
		{
			mTime++;
			if (mTime == 3)
			{
				HAPI.SetControllerRumble(0, 0, 0);
			}
				
			if (mTime >= 5)
			{
				HAPI.SetControllerRumble(0, 36000, 36000);
				WORLD.FireBullet(mBulletSpawn, mDirection, 1);
				AUDIO.PlayAudio("gunShot.wav");
				mTime = 0;

			}
		}
		if (!r_data.analogueButtons[HK_ANALOGUE_RIGHT_TRIGGER])
		{
			HAPI.SetControllerRumble(0, 0, 0);
		}
		if (r_data.digitalButtons[HK_DIGITAL_START])
		{
			HAPI.Close();
		}
			

		
	}
	
	SetPosition(pos);

}

