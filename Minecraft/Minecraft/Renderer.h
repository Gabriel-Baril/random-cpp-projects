#pragma once
#include "cpp_includes.h"
#include "opengl_includes.h"
#include "Block.h"
#include "Chunk.h"
#include "RendererOptimizer.h"
#include "Application.h"
#include "Plane.h"

class Renderer
{
public:
	Renderer();
	void filter(std::vector<std::vector<Chunk>>&);
	void render(const Block&);
	static void render(const std::vector<std::vector<Chunk>>&, const GLuint&, const glm::mat4&);
};