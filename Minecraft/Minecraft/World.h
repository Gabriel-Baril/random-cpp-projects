#pragma once
#include "cpp_includes.h"
#include "opengl_includes.h"
#include "Chunk.h"

#define WORLD_SIZE_X 16
#define WORLD_SIZE_Y 1
#define WORLD_SIZE_Z 16

class World {
public:
	World() {}
	void render();
	void update();
	void generate();

	std::vector<std::vector<Chunk>> getChunks() const;
private:
	std::vector<std::vector<Chunk>> chunks;
};