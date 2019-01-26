#pragma once
#include "Game.h"
Game::Game()
{
}


Game::~Game()
{
}

void Game::Run()
{
	world World;
	World.levelLoad();
	World.levelRender();
}
	

	
	

	
	

	

