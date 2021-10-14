#include "Block.h"

Block::Block(const glm::ivec3& pos)
{
	this->pos = pos;
}

glm::ivec3 Block::getPositionRelativeToWorld() const
{
	return this->pos;
}

glm::ivec3 Block::getPositionRelativeToChunk() const
{
	return glm::ivec3(this->pos.x % CHUNK_SIZE_X,this->pos.y,this->pos.z % CHUNK_SIZE_Z);
}

Chunk& Block::getChunk() const
{
	return engine.getWorld().getChunks()[(int)(this->pos.x / CHUNK_SIZE_X)][(int)(this->pos.z / CHUNK_SIZE_Z)];
}
