#pragma once
#define BLOCK_SIZE_X 2
#define BLOCK_SIZE_Y 2
#define BLOCK_SIZE_Z 2
#include "cpp_includes.h"
#include "opengl_includes.h"
#include "Chunk.h"
#include "main.h"

class Block 
{
public:
	Block(const glm::ivec3&);
	glm::ivec3 getPositionRelativeToWorld() const;
	glm::ivec3 getPositionRelativeToChunk() const;
	Chunk& getChunk() const;
private:
	glm::ivec3 pos;
	bool right = true;
	bool left = true;
	bool up = true;
	bool down = true;
	bool back = true;
	bool front = true;
};
