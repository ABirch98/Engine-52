#pragma once
#include "Entity.h"
class SceneryEntity : public Entity
{
public:
	SceneryEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int Framesize, int FrameCount);
	~SceneryEntity();

	void Update() override final;
	EContingent GetCont() const override final {
		return mCont;
	};
};

