#pragma once

#include "Renderer.h"

template<typename T>
class OpenGlRendererAPI : public Renderer<T>
{
	public OpenGlRendererAPI();
	void render(const PolygonData<T>&) override;
	void render(const CircleData<T>&) override;
	void 
};
