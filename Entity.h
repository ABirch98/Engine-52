//Engine52 V1.09 World Space Handler 
//Entity.h Parent Entity class Holds member Data for All entities
#pragma once
#include "Vector2.h"
#include <string>
#include <HAPI_lib.h>

using namespace HAPISPACE;
class Graphics;

enum class EContingent
{
	ePlayer,
	eEnemy,
	eNeutral,
	eScenery
};

class Entity 
{
private:
	Vector2 mPosition{ 0,0 };
	Vector2 mOldPosition{ 0,0 };
protected:
	Vector2 mBulletSpawn{ GetPosition()};
	DWORD mLastTimeAnimated{0};
	DWORD mAnimationTime{50};
	std::string mTextureName;
	int mFrameWidth{ 0 };
	int mFrameHeight{ 0 };
	int mFrameNo{ 0 };
	int mFrameSize{ 0 };
	int mFrameCount{ 0 };
	int mHealth{ 0 };
	int mDamageCooldown { 30 };
	int mDirection{ -1 };
	int mDamage{ 0 };
	bool mAlive{ true };
	int mHealthLeft{ 0 };
	bool mAnimationFinished{ false };
	float mSpeed{ 8.0f };
	EContingent mCont{ EContingent::eNeutral };
	DWORD mKTickTime{ 250 };
	DWORD mLastTick = 0;

public:
	Entity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount);
	virtual ~Entity();
	void Reset();
	void ResetHealth();
	void SetDirection(int Direction) { mDirection = Direction; }
	void SetAlive();
	void Render(Graphics& rGraphics, float S);
	void RenderFast(Graphics& rGraphics);
	void SetPosition(Vector2 NewPos) { mOldPosition = mPosition;  mPosition = NewPos; }
	void CheckCollision(Graphics& rGraphics, Entity& rOther);
	void TakeDamage(int Amount);
	Vector2 GetPosition() const { return mPosition; };
	void GetNewCont(int Cont);
	bool Alive();
	bool CanCollideWith(EContingent x, EContingent y);
	virtual void Update() = 0;

	virtual EContingent GetCont() const = 0;
};

