#include "Chunk.h"
Random random = Random(0, 1, 10);


Chunk::Chunk(const glm::ivec3& pos)
{
	this->pos = pos;
}

void Chunk::generate()
{
	int r;
	for (GLuint x = 0; x < CHUNK_SIZE_X; x++)
	{
		blocks.push_back(std::vector<std::vector<Block>>());
		for(GLuint z = 0;z < CHUNK_SIZE_Z; z++)
		{
			blocks[x].push_back(std::vector<Block>());
			r = (int)random.next();
			for (GLuint y = 0; y < r; y++)
			{
				int x_final = this->pos.x * CHUNK_SIZE_X * BLOCK_SIZE_X + x * BLOCK_SIZE_X;
				int z_final = this->pos.z * CHUNK_SIZE_Z * BLOCK_SIZE_Z + z * BLOCK_SIZE_Z;
				float y_final = this->pos.y * CHUNK_SIZE_Y * BLOCK_SIZE_Y + y * BLOCK_SIZE_Y;
				blocks[x][z].push_back(Block(vec3(x_final, y_final, z_final)));
			}
		}
	}
}

glm::ivec3 Chunk::getPosition() const
{
	return this->pos;
}

glm::ivec3 Chunk::getPositionRelativeToWorld() const
{
	glm::ivec3 pos = this->getPosition();
	return glm::ivec3(pos.x * CHUNK_SIZE_X, pos.y * CHUNK_SIZE_Y, pos.z * CHUNK_SIZE_Z);
}

std::vector<std::vector<std::vector<Block>>> Chunk::getBlocks() const
{
	return this->blocks;
}
