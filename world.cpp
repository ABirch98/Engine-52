//Engine 52 V1.09 World Space Handler
//world.cpp Hold the function implementations for the world space handler
#include "world.h"
#include "Graphics.h"
#include "EnemyEntity.h"
#include "playerEntity.h"
#include "BackGroundEntity.h"
#include "ExplosionEntity.h"
#include "BaseEntity.h"
#include "BulletEntity.h"
#include <string>
#include <cassert>
#include <random>
#include <time.h>
#include "Audio.h"
#include "SceneryEntity.h"

world *world::_mpInstance{ nullptr };
world::world()
{
	srand(time(0)); 
}
world& world::GetInstance()
{
	if (_mpInstance == nullptr)
	{
		_mpInstance = new world;
		return *_mpInstance;
	}
	else
		return *_mpInstance;
}

void world::DeleteInstance()
{
	delete _mpInstance;
}



world::~world()
{
	delete mpGraphics;

	for (auto P : mClipVector)
	{
		delete P;
	}
		
	for (auto P : mFastVector)
	{
		delete P;
	}
}

bool world::LoadLevel()
{
	//LOAD SPRITE DATA --------------------------------------------------------------------------------------------
	if (!mpGraphics->CreateSprite("data\\player.png", "player"))
	{
		HAPI.UserMessage("Couldn't find texture playerSprite.tga", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\Enemy.png", "Enemy"))
	{
		HAPI.UserMessage("Couldn't find Enemy.png", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\boom.png", "explosion"))
	{
		HAPI.UserMessage("Couldn't find texture boom.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\obj_barrels.png", "barrels"))
	{
		HAPI.UserMessage("Couldn't find texture obj_barrels.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\obj_bags1.png", "bags1"))
	{
		HAPI.UserMessage("Couldn't find texture obj_bags1.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\obj_bags2.png", "bags2"))
	{
		HAPI.UserMessage("Couldn't find texture ogj_bags2.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\rock9.png", "floor"))
	{
		HAPI.UserMessage("Couldn't find texture rock9.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\obj_jeep2.png", "jeepright"))
	{
		HAPI.UserMessage("Couldn't find texture obj_jeep2.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\obj_jeep3.png", "jeepleft"))
	{
		HAPI.UserMessage("Couldn't find texture obj_jeep3.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\obj_lookout.png", "base"))
	{
		HAPI.UserMessage("Couldn't find texture obj_lookout.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\bullet.png", "bullet"))
	{
		HAPI.UserMessage("Couldn't find texture bullet.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!mpGraphics->CreateSprite("data\\BarbedW.png", "Wire"))
	{
		HAPI.UserMessage("Couldn't find texture BarbedW.PNG", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	//LOAD SPRITE DATA --------------------------------------------------------------------------------------------

	//BACKGROUND-------------------------------------------------------------

	BackGroundEntity *p_floor = new BackGroundEntity("floor", 800, 600, 0, 0);
	mFastVector.push_back(p_floor);
	p_floor->SetPosition(Vector2(0, 0));

	BackGroundEntity *p_sand_bagsL1 = new BackGroundEntity("bags1", 85, 40, 0, 0);
	mClipVector.push_back(p_sand_bagsL1);
	p_sand_bagsL1->SetPosition(Vector2(20, 355));

	BackGroundEntity *p_sand_bagsL = new BackGroundEntity("bags1", 85, 40, 0, 0);
	mClipVector.push_back(p_sand_bagsL);
	p_sand_bagsL->SetPosition(Vector2(0, 380));


	BackGroundEntity *p_sand_bagsCML = new BackGroundEntity("bags1", 85, 40, 0, 0);
	mClipVector.push_back(p_sand_bagsCML);
	p_sand_bagsCML->SetPosition(Vector2(305, 355));

	BackGroundEntity *p_sand_bagsCL = new BackGroundEntity("bags1", 85, 40, 0, 0);
	mClipVector.push_back(p_sand_bagsCL);
	p_sand_bagsCL->SetPosition(Vector2(235, 355));

	BackGroundEntity *p_sand_bagsCMR = new BackGroundEntity("bags1", 85, 40, 0, 0);
	mClipVector.push_back(p_sand_bagsCMR);
	p_sand_bagsCMR->SetPosition(Vector2(385, 355));

	BackGroundEntity *p_sand_bagsCR = new BackGroundEntity("bags1", 85, 40, 0, 0);
	mClipVector.push_back(p_sand_bagsCR);
	p_sand_bagsCR->SetPosition(Vector2(465, 355));

	BackGroundEntity *p_sand_bagsR1 = new BackGroundEntity("bags1", 85, 40, 0, 0);
	mClipVector.push_back(p_sand_bagsR1);
	p_sand_bagsR1->SetPosition(Vector2(690, 355));

	BackGroundEntity *p_sand_bagsR = new BackGroundEntity("bags1", 85, 40, 0, 0);
	mClipVector.push_back(p_sand_bagsR);
	p_sand_bagsR->SetPosition(Vector2(715, 380));

	BackGroundEntity *p_big_sand_bags = new BackGroundEntity("bags2", 128, 61, 0, 0);
	mClipVector.push_back(p_big_sand_bags);
	p_big_sand_bags->SetPosition(Vector2(335, 400));

	BackGroundEntity *p_barrelsR = new BackGroundEntity("barrels", 55, 47, 0, 0);
	mClipVector.push_back(p_barrelsR);
	p_barrelsR->SetPosition(Vector2(459, 380));

	BackGroundEntity *p_barrelsL = new BackGroundEntity("barrels", 55, 47, 0, 0);
	mClipVector.push_back(p_barrelsL);
	p_barrelsL->SetPosition(Vector2(282, 380));

	BackGroundEntity *p_jeep_left = new BackGroundEntity("jeepright", 150, 98, 0, 0);
	mClipVector.push_back(p_jeep_left);
	p_jeep_left->SetPosition(Vector2(96, 320));

	BackGroundEntity *p_jeep_right = new BackGroundEntity("jeepleft", 150, 98, 0, 0);
	mClipVector.push_back(p_jeep_right);
	p_jeep_right->SetPosition(Vector2(548, 320));

	SceneryEntity *p_barbed_wire = new SceneryEntity("Wire", 64, 64, 0, 0);
	mClipVector.push_back(p_barbed_wire);
	p_barbed_wire->SetPosition(Vector2(245, 160));

	SceneryEntity *p_barbed_wire1 = new SceneryEntity("Wire", 64, 64, 0, 0);
	mClipVector.push_back(p_barbed_wire1);
	p_barbed_wire1->SetPosition(Vector2(190, 160));

	SceneryEntity *p_barbed_wire2= new SceneryEntity("Wire", 64, 64, 0, 0);
	mClipVector.push_back(p_barbed_wire2);
	p_barbed_wire2->SetPosition(Vector2(523, 220));

	SceneryEntity *p_barbed_wire3 = new SceneryEntity("Wire", 64, 64, 0, 0);
	mClipVector.push_back(p_barbed_wire3);
	p_barbed_wire3->SetPosition(Vector2(587, 220));


	//BACKGROUND-------------------------------------------------------------
	//BASES----------------------------------------------------------
	BaseEntity *p_base1 = new BaseEntity("base", 168, 317, 0, 0);
	mClipVector.push_back(p_base1);
	p_base1->SetPosition(Vector2(90, 380));

	BaseEntity *p_base2 = new BaseEntity("base", 168, 317, 0, 0);
	mClipVector.push_back(p_base2);
	p_base2->SetPosition(Vector2(540, 380));

	//PLAYER---------------------------------------------------------

	playerEntity *p_new_player = new playerEntity("player", 40, 60, 40, 20);
	mClipVector.push_back(p_new_player);
	p_new_player->SetPosition(Vector2(374, 530));

	//PLAYER---------------------------------------------------------

	//BULLETS--------------------------------------------------------
	for (int i = 0; i < 2000; i++)
	{
		CreateBullet("bullet.png", "bullet" + std::to_string(i));
	}

	//BULLETS--------------------------------------------------------
	

	//ENEMIES-----------------------------------------------------------

	for (int i = 0; i < 500; i++)
	{
		CreateEnemy("Enemy" + std::to_string(i));
	}

	//ENEMIES-----------------------------------------------------------

	//EXPLOSIONS---------------------------------------------------------------------

	for (int i = 0; i < 1000; i++)
	{
		CreateExplosion("explosion" + std::to_string(i));
	}

	//EXPLOSIONS---------------------------------------------------------------------

	//SOUNDS------------------------------------------------------------------------------------------

	if (!AUDIO.LoadAudio("Recording.wav"))
	{
		HAPI.UserMessage("Couldn't find sound Recording.WAV", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!AUDIO.LoadAudio("gunShot.wav"))
	{
		HAPI.UserMessage("Couldn't find sound gunShot.WAV", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	if (!AUDIO.LoadAudio("Explosion+3.wav"))
	{
		HAPI.UserMessage("Couldn't find sound Explosion+3.WAV", "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	return true;

	//SOUNDS------------------------------------------------------------------------------------------
}
constexpr DWORD K_KICK_TIME{ 50 };
constexpr DWORD LONG_WAIT{ 200 };

void world::Update()//change the world state of all entities 
{ 
	DWORD last_tick = 0;
	//HAPISPACE::HAPI_TStreamedMediaOptions options(0, true, 1);
	while (HAPI.Update())
	{
		DWORD since_last_tick = (HAPI.GetTime() - last_tick);
		if (since_last_tick >= K_KICK_TIME)
		{
			for (auto P : mClipVector)
			{
				
				if (P->Alive())
				{
					
					P->Update();
					//HAPI.PlayStreamedMedia("Background", options, 10);
				}
				
			}
			
			last_tick = HAPI.GetTime();

			for (size_t i = 0; i < mClipVector.size(); i++)
			{
				for (size_t t = i+1; t < mClipVector.size(); t++)
				{
					mClipVector[i]->CheckCollision(*mpGraphics, *mClipVector[t]);
				}
			}
			since_last_tick = 0;
		}

		for (auto P : mFastVector)
		{
			P->RenderFast(*mpGraphics);
		}
		

		float s = since_last_tick / (float)K_KICK_TIME;
		assert(s >= 0 && s <= 1.0f);

		for (auto P : mClipVector)
		{
			if (P->Alive())
			{
				P->Render(*mpGraphics, s);
			}
				
		}
		HAPI.RenderText(0, 0, HAPI_TColour(255, 0, 0), "Enemies Left: " + std::to_string(mEnemiesLeft), 28, eBold);
		HAPI.RenderText(600, 0, HAPI_TColour(255, 0, 0), "Score: " + std::to_string(mScore), 28, eBold);
	
		if (mEnemiesLeft < 0)
		{
			mpGraphics->ClearToGreyscale(69);
			HAPI.RenderText(100, 150, HAPI_TColour(255, 0, 0), "YOU WIN !!!", 100, eBold);
			HAPI.RenderText(100, 300, HAPI_TColour(255, 0, 0), "Score: " + std::to_string(mScore), 100, eBold);

		}
		if (mBasesLeft == 0 || mLives == 0)
		{
			mpGraphics->ClearToGreyscale(69);
			HAPI.RenderText(100, 150, HAPI_TColour(255, 0, 0), "YOU LOSE....", 100, eBold);
			HAPI.RenderText(100, 300, HAPI_TColour(255, 0, 0), "Score: " + std::to_string(mScore), 100, eBold);

		}
	
	}
	


}


void world::FireBullet(Vector2 SpawnPoint, int Direction, int cont)
{
	
		if (mBulletMap.at("bullet" + std::to_string(mBulletID))->Alive())
		{
			mBulletID++;
		}
		else
		{
			mBulletMap.at(std::string("bullet" + std::to_string(mBulletID)))->GetNewCont(cont);
			mBulletMap.at(std::string("bullet" + std::to_string(mBulletID)))->SetPosition(SpawnPoint);// becuase it sets position and sets alive before it updates looks like
			mBulletMap.at(std::string("bullet" + std::to_string(mBulletID)))->SetDirection(Direction);
			mBulletMap.at(std::string("bullet" + std::to_string(mBulletID)))->SetAlive();//bullets are being pulled out of thin air 
			mBulletMap.at(std::string("bullet" + std::to_string(mBulletID)))->ResetHealth();
			
			mBulletID++;
			
		}
		if (mBulletID >= 1999)
		{
			mBulletID = 0;
		}
}

void world::SpawnExplosion(Vector2 SpawnPoint)
{
	if (mExplosionMap.at("explosion" + std::to_string(mExplosionID))->Alive())
	{
		mExplosionID++;
	}
	else
	{
		mExplosionMap.at(std::string("explosion" + std::to_string(mExplosionID)))->SetPosition(SpawnPoint);// becuase it sets position and sets alive before it updates looks like
		mExplosionMap.at(std::string("explosion" + std::to_string(mExplosionID)))->SetAlive();//bullets are being pulled out of thin air 

		mExplosionID++;

	}
	if (mExplosionID >= 999)
	{
		mExplosionID = 0;
	}
}

void world::SetScore(int Score)
{
	mScore += Score;
}



void world::CreateBullet(const std::string& rFilename, const std::string& rName)
{
	BulletEntity *p_new_bullet = new BulletEntity();
	mBulletMap[rName] = p_new_bullet;
	mClipVector.push_back(mBulletMap.at(rName));
}

void world::CreateEnemy(const std::string& rName)
{
	float x = (float)(rand() % 725 + 50);
	float y = -(float)(rand() % 350 + 20);
	EnemyEntity *p_new_enemy = new EnemyEntity("Enemy", 40, 60, 40, 20);
	mEnemyMap[rName] = p_new_enemy;
	mEnemyMap.at(rName)->SetPosition(Vector2 (x, y));
	mClipVector.push_back(mEnemyMap.at(rName));
	
}

void world::CreateExplosion(const std::string & rName)
{
	ExplosionEntity *p_new_explosion = new ExplosionEntity("explosion", 64, 64, 64, 16);
	mExplosionMap[rName] = p_new_explosion;
	mClipVector.push_back(mExplosionMap.at(rName));
	
}


void world::Run() // load the graphics 
{
	mpGraphics = new Graphics;
	if (!mpGraphics->Initialise())
		return;

	if (!LoadLevel())
		return;	

	Update();
	

}


