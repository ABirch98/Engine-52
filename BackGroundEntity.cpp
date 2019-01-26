//Engine52 V1.08 World Space Handler 
//BackgroundEntity.cpp Child of Entity class Holds implentation of Functions for background entities (Un-Interactable objects)
#include "BackGroundEntity.h"



BackGroundEntity::BackGroundEntity(const std::string& TextureName, int FrameWidth, int FrameHeight, int FrameSize, int FrameCount) : Entity(TextureName, FrameWidth, FrameHeight, FrameSize, FrameCount)
{
}


BackGroundEntity::~BackGroundEntity()
{
}

void BackGroundEntity::Update() //gets and sets entity position
{
	Vector2 pos{ GetPosition() };
	SetPosition(pos);
}