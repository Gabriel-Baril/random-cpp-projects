#pragma once
#include "cpp_includes.h"
#include "opengl_includes.h"
#include "Block.h"
#include "Random.h"

#define CHUNK_SIZE_X 8
#define CHUNK_SIZE_Y 3
#define CHUNK_SIZE_Z 8

class Chunk
{
public:
	Chunk() {};
	Chunk(const glm::ivec3&);
	void generate();
	glm::ivec3 getPosition() const;
	glm::ivec3 getPositionRelativeToWorld() const;
	std::vector<std::vector<std::vector<Block>>> getBlocks() const;
private:
	glm::ivec3 pos;
	std::vector<std::vector<std::vector<Block>>> blocks;
	//vec2[CHUNK_SIZE_X + 1][CHUNK_SIZE_Y + 1] signature;
};