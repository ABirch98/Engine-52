//Engine52 V1.09 World Space Handler 
//ExplosionEntity.h Entity class Holds member Data for Explosion entities
#pragma once
#include "Entity.h"
#include <random>
class ExplosionEntity :
	public Entity
{
public:
	ExplosionEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount);
	~ExplosionEntity();
	void Update() override final;
	EContingent GetCont() const override final {
		return EContingent::eScenery;
	};
private:
	int mTime{ 5 };
};

