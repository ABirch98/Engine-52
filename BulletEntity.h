//Engine52 V1.08 World Space Handler 
//BulletEntity.h Child of Entity class Holds specific member Data for Bullet entities 
#pragma once
#include "Entity.h"
class BulletEntity :
	public Entity
{	
public:
	BulletEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount);
	BulletEntity();
	~BulletEntity();
	void Update() override final;
	
	

	EContingent GetCont() const override final {
		return mCont;
	}

};

