//Engine52 V1.08 World Space Handler 
//Entity.cpp Parent Entity class Holds Implementation of fucntions for All entities
#include "Entity.h"
#include "Graphics.h"


Entity::Entity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount) : mTextureName(TextureName), mFrameWidth(FrameWidth), mFrameHeight(FrameHeight), mFrameSize(FrameSize), mFrameCount(FrameCount)
{
	
}




Entity::~Entity()
{
}

void Entity::Reset()
{
	if (mAnimationFinished = true)
	{
		mFrameNo = 0;
		

	}
}

void Entity::ResetHealth()
{
	mHealthLeft = mHealth;
}

void Entity::GetNewCont(int Cont)
{
	if (Cont == 0)
	{
		mCont = EContingent::eNeutral;
	}
	if (Cont == 1)
	{
		mCont = EContingent::ePlayer;
	}
	if (Cont == 2)
	{
		mCont = EContingent::eEnemy;
	}
	if (Cont == 3)
	{
		mCont = EContingent::eScenery;
	}
	else
		return;
}

bool Entity::Alive()
{
	return mAlive;
}
bool Entity::CanCollideWith(EContingent x, EContingent y)
{
	if (y == x || x == y)
		return false;
	if ((x == EContingent::eNeutral) || (y == EContingent::eNeutral))
		return false;
	if ((x == EContingent::ePlayer && y == EContingent::eScenery) || (y == EContingent::ePlayer && x == EContingent::eScenery))
		return false;
	else
		return true;
	
}
void Entity::Render(Graphics& rGraphics, float s)
{

	if (!Alive())
		return;
	Vector2 inter_pos(mOldPosition + (mPosition - mOldPosition) * s);
	rGraphics.ClipBlit(mTextureName, (int)inter_pos.mX, (int)inter_pos.mY, mFrameNo, mFrameWidth, mFrameHeight, mFrameSize);

	if (HAPI.GetTime() - mLastTimeAnimated>= mAnimationTime)
	{
		mFrameNo++;
		mLastTimeAnimated = HAPI.GetTime();
		if (mFrameNo == mFrameCount)
		{
			mAnimationFinished = true;
			Reset();
			mAnimationFinished = false;
		}
	}
}

void Entity::RenderFast(Graphics& rGraphics)
{
	rGraphics.FastBlit(mTextureName, (int)mPosition.mX, (int)mPosition.mY);
}



void Entity::CheckCollision(Graphics& rGraphics, Entity& rOther)
{

	if (!Alive()||!rOther.Alive())
		return;

	if (!CanCollideWith(GetCont(),rOther.GetCont()))
		return;

	Rectangle check_rectangle(rGraphics.GetRect(mTextureName, mFrameCount));

	int w(check_rectangle.Width());

	check_rectangle.mLeft += w/5;
	check_rectangle.mRight -= w/5;


	Rectangle other_rectangle(rGraphics.GetRect(rOther.mTextureName,rOther.mFrameCount));

	check_rectangle.Transform((int)mPosition.mX, (int)mPosition.mY);
	other_rectangle.Transform((int)rOther.mPosition.mX, (int)rOther.mPosition.mY);

	
	if (!check_rectangle.OutsideOf(other_rectangle) || other_rectangle.Contains(check_rectangle))
	{
		mDamageCooldown++;
		if (mDamageCooldown >= 30)
		{
			//HAPI.PlaySound("gunShot.wav"); debug
			TakeDamage(rOther.mDamage);
			rOther.TakeDamage(mDamage);
			
			mDamageCooldown = 0;
			
		}
	
	}
}

void Entity::TakeDamage(int Amount)
{
	mHealthLeft -= Amount;
}
void Entity::SetAlive()
{
	mAlive = true;
}
