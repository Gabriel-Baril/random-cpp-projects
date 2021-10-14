#include "World.h"

void World::generate()
{
	for (GLuint x = 0; x < WORLD_SIZE_X; x++)
	{
		this->chunks.push_back(std::vector<Chunk>());
		for (GLuint z = 0; z < WORLD_SIZE_Z; z++)
		{
			Chunk chunk = Chunk(vec3(x, 0, z));
			chunk.generate();
			this->chunks.at(x).push_back(chunk);
		}
	}

	//std::cout << this->chunks.size() << std::endl;
}

std::vector<std::vector<Chunk>> World::getChunks() const
{
	return this->chunks;
}

void World::render()
{
}

void World::update()
{

}
