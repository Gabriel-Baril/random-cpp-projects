#pragma once
#include <string>
#include "IComponent.h"
#include "IComponentRenderer.h"

struct TextLabel : IComponent {
	IComponentRenderer<TextLabel>* renderer;
	std::string content; // UIText
	float x;
	float y;

	TextLabel(const std::string& content, float x, float y) : content{ content }, x{ x }, y{ y } {}

	void draw() const override
	{
		renderer->draw(*this);
	}
};