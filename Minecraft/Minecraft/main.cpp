#pragma once
#include <functional>
#include <vector>
#include "cpp_includes.h"
#include "opengl_includes.h"
#include "Application.h"
#include "Camera.h"
#include "World.h"
#include "Block.h"

#include "main.h" // engine object in this file

extern Application engine;

int main(void)
{
	engine.init();
	engine.update();
	engine.cleanup();
	
	return EXIT_SUCCESS;
}