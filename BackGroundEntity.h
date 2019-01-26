//Engine52 V1.08 World Space Handler 
//BackgroundEntity.h Child of Entity class Holds specific Member Data for background entities (Un-Interactable objects)
#pragma once
#include "Entity.h"
class BackGroundEntity : public Entity
{
public:
	BackGroundEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount);
	~BackGroundEntity();

	void Update() override final;
	EContingent GetCont() const override final { //returns the side(contingency) of the entity
		return EContingent::eNeutral;
	};
};

