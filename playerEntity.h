//Engine52 V1.09 World Space Handler 
//PlayerEntity.h Entity class Holds member Data for player entities
#pragma once
#include "Entity.h"
class playerEntity : public Entity
{
public:
	playerEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount);
	~playerEntity();

	void Update() override final;

	EContingent GetCont() const override final {
		return mCont;
	}
private:
	int mTime{ 5 };
};

