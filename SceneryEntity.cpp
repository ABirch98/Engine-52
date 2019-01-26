#include "SceneryEntity.h"



SceneryEntity::SceneryEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount) : Entity(TextureName, FrameWidth, FrameHeight, FrameSize, FrameCount)
{
	mAlive = true;
	mDamage = 0;
	GetNewCont(3);
}


SceneryEntity::~SceneryEntity()
{
}

void SceneryEntity::Update()
{
	mAlive = true;
	Vector2 pos{ GetPosition() };
	SetPosition(pos);
}