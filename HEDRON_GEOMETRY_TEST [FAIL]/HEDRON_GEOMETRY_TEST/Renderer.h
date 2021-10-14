#pragma once
#include <string>
#include "PolygonData.h"
#include "CircleData.h"


template<typename T>
class Renderer
{
public:
	Renderer();
	virtual void render(const PolygonData<T>&) = 0;
	virtual void render(const CircleData<T>&) = 0;
	virtual std::string get_name() = 0;
	virtual ~Renderer();
};