//Engine52 V1.09 World Space Handler 
//EnemyEntity.h Entity class Holds member Data for Enemy entities
#pragma once
#include "Entity.h"
class EnemyEntity :
	public Entity
{
public:
	EnemyEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount);
	~EnemyEntity();
	

	void Update() override final;
	EContingent GetCont() const override final {
		return mCont;
	};
private:
	int mTime{ 5 };
	float mZ{ 0 };
	int mPoints{ 500 };
};

