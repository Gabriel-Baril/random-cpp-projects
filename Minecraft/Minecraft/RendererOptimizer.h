#pragma once
#include "Application.h"
#include "cpp_includes.h"
#include "opengl_includes.h"
#include "World.h"
#include "Plane.h"

#define RENDER_DISTANCE 2

class RendererOptimizer
{
private:
	static bool checkIfPointFrontOfPlane(Plane plane, vec3 point)
	{
		return glm::dot(plane.A - point, plane.normal) > 0;
	}
public:
	static std::vector<Chunk> selectChunkToLoad(const std::vector<std::vector<Chunk>>& chunks);
	static std::vector<Chunk> viewFrustumCullingAlgorithm(const std::vector<Chunk>& chunks, std::vector<Plane> viewFrustumPlanes);
	static std::vector<Block> selectNonObstruedBlocks(const std::vector<std::vector<std::vector<Block>>>& blocks);
};