#pragma once
#include "ISceneLayer.h"
#include <iostream>


class PlayerStatLayer : public ISceneLayer 
{
public:
	PlayerStatLayer() : ISceneLayer("PlayerStatLayer") {}

	virtual void update(Window* window, Time dt)
	{
		std::cout << "PlayerStatLayer update" << std::endl;
	}

	virtual void render(Window* window, Time dt)
	{
		std::cout << "PlayerStatLayer render" << std::endl;
	}
};