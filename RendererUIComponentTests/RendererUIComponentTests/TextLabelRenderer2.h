#pragma once
#include "TextLabel.h"
#include <iostream>

struct TextLabelRenderer2 : IComponentRenderer<TextLabel>
{
	void draw(const TextLabel& component) const override
	{
		std::cout << "Draw method 2" << std::endl;
		std::cout << "Content : " << component.content << " at (" << component.x << ", " << component.y << ")" << std::endl;
	}
};