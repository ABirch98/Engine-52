//Engine 52 V1.09 World Space Handler
//world.h Hold the main member data for the world space handler 
#pragma once
#include <vector>
#include "Vector2.h"
#include <unordered_map>

class Graphics;
class Entity;
class world
{
private:
	Graphics *mpGraphics{ nullptr };
	static world *_mpInstance;
	world();
	bool LoadLevel();
	void Update();
	int mBulletID{ 0 };
	int mExplosionID{ 0 };
	int mEnemiesLeft{ 100000 };
	int mLives{ 2 };
	int mBasesLeft{ 2 };
	int mScore{ 0 };
	
	std::vector<Entity*> mClipVector;
	std::vector<Entity*> mFastVector;
	std::unordered_map<std::string, Entity*> mBulletMap;
	std::unordered_map<std::string, Entity*> mEnemyMap;
	std::unordered_map<std::string, Entity*> mExplosionMap;
public:
	static world& GetInstance();
	static void DeleteInstance();
	void KillEnemy() {
		mEnemiesLeft--;
	}
	void KillBase() {
		mBasesLeft--;
	}
	void KillPlayer() {
		mLives--;
	}
	void FireBullet(Vector2 SpawnPoint, int Direction, int cont);
	void SpawnExplosion(Vector2 SpawnPoint);
	void SetScore(int Score);
	int GetScore{ 0 };//dont know why this is here TODO: investigate...
	void CreateBullet(const std::string& rFilename, const std::string& rName);
	void CreateEnemy(const std::string& rName);
	void CreateExplosion(const std::string& rName);
	~world();

	void Run();
};

#define WORLD world::GetInstance()

