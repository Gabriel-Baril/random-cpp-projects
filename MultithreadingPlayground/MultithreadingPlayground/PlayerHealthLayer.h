#include "ISceneLayer.h"
#include <iostream>


class PlayerHealthLayer : public ISceneLayer
{
public:
	PlayerHealthLayer() : ISceneLayer("PlayerHealthLayer") {}

	virtual void update(Window* window, Time dt)
	{
		std::cout << "PlayerHealthLayer update" << std::endl;
	}

	virtual void render(Window* window, Time dt)
	{
		std::cout << "PlayerHealthLayer render" << std::endl;
	}
};