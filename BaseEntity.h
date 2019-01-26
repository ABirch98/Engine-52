//Engine52 V1.08 World Space Handler 
//BaseEntity.h Child of Entity class Holds specific Member Data for Base Entities
#pragma once
#include "Entity.h"
class BaseEntity :
	public Entity
{
public:
public:
	BaseEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount);
	~BaseEntity();

	void Update() override final;
	EContingent GetCont() const override final {
		return mCont;
		
	};
	const int mPoints{ -10000 };
};

