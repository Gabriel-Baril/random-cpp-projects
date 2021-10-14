#pragma once
#include "IComponent.h"
#include <type_traits>

template<typename T>
struct IComponentRenderer
{
	virtual void draw(const T& component) const = 0;
};
