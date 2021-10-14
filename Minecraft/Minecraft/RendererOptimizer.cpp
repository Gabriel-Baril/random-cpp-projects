#include "RendererOptimizer.h"

std::vector<Chunk> RendererOptimizer::selectChunkToLoad(const std::vector<std::vector<Chunk>>& chunks)
{
	std::vector<Chunk> toLoad;

	int x = (int)(Application::camera.getPosition().x / CHUNK_SIZE_X) / 2;
	int z = (int)(Application::camera.getPosition().z / CHUNK_SIZE_Z) / 2;

	int offSet = 1;
	int factor = 2;

	for (int i = -RENDER_DISTANCE; i < RENDER_DISTANCE + 1; i++)
	{
		for (int j = 0; j < offSet; j++)
		{
			int o_x = x - RENDER_DISTANCE + abs(i) + j;
			int o_z = z + i;

			if (o_x >= 0 && o_x <= WORLD_SIZE_X && o_z >= 0 && o_z <= WORLD_SIZE_Z) toLoad.push_back(chunks[o_x][o_z]);
		}

		if (offSet >= 2 * RENDER_DISTANCE + 1) factor = -2;
		offSet += factor;
	}
	return toLoad;
}

std::vector<Chunk> RendererOptimizer::viewFrustumCullingAlgorithm(const std::vector<Chunk>& chunks, std::vector<Plane> viewFrustumPlanes)
{
	std::vector<Chunk> output;
	bool accepted = true;
	for (GLuint i = 0; i < chunks.size(); i++)
	{
		accepted = true;
		glm::ivec3 chunk_pos = vec3(chunks[i].getPositionRelativeToWorld().x + CHUNK_SIZE_X/2, chunks[i].getPositionRelativeToWorld().y, chunks[i].getPositionRelativeToWorld().z + CHUNK_SIZE_Z/2);
		for (GLuint j = 0; j < 6; j++)
		{
			if (j == 0 || j == 1 || j == 4)
			{
				if (checkIfPointFrontOfPlane(viewFrustumPlanes[j], chunk_pos)) accepted = false;
				continue;
			}
			if (j == 2 || j == 3 || j == 5)
			{
				if (!checkIfPointFrontOfPlane(viewFrustumPlanes[j], chunk_pos)) accepted = false;
				continue;
			}
		}
		if (accepted) output.push_back(chunks[i]);
	}
	return output;
}

std::vector<Block> RendererOptimizer::selectNonObstruedBlocks(const std::vector<std::vector<std::vector<Block>>>& blocks)
{
	std::vector<Block> visible_blocks;
	for(GLuint x = 0;x < blocks.size();x++)
	{
		for(GLuint y = 0;y < blocks[x].size();y++)
		{
			for(GLuint z = 0;z < blocks[x][y].size();z++)
			{
				if (x + 1 >= CHUNK_SIZE_X || x - 1 <= 0 || y + 1 >= CHUNK_SIZE_Y || y - 1 <= 0 || z + 1 >= CHUNK_SIZE_Z || z - 1 <= 0)
				{
					visible_blocks.push_back(blocks[x][y][z]);
					continue;
				}
				
				if( !(blocks[x + 1][y][z].getPositionRelativeToWorld().x - 1 == blocks[x][y][z].getPositionRelativeToWorld().x &&
					blocks[x - 1][y][z].getPositionRelativeToWorld().x + 1 == blocks[x][y][z].getPositionRelativeToWorld().x &&
					blocks[x][y - 1][z].getPositionRelativeToWorld().y - 1 == blocks[x][y][z].getPositionRelativeToWorld().y &&
					blocks[x][y + 1][z].getPositionRelativeToWorld().y + 1 == blocks[x][y][z].getPositionRelativeToWorld().y &&
					blocks[x][y][z - 1].getPositionRelativeToWorld().z - 1 == blocks[x][y][z].getPositionRelativeToWorld().z &&
					blocks[x][y][z + 1].getPositionRelativeToWorld().z + 1 == blocks[x][y][z].getPositionRelativeToWorld().z) )
				visible_blocks.push_back(blocks[x][y][z]);
			}
		}
	}
	return visible_blocks;
}

