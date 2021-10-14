#pragma once
#include "cpp_includes.h"
#include "opengl_includes.h"
#include "Shader.h"
#include "Camera.h"
#include "World.h"
#include "Chunk.h"
#include "Block.h"
#include "Renderer.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

using glm::vec3;

class Application {
private:
	struct TimeData {
		long totalFPS = 0;
		long currentFPS = 0;
		double lastTime = glfwGetTime();
		double currentTime = 0;
		long lastFPS = 0;
		double ms_per_frame = 0;
		double delta_time = 0;
		long getDifferential() { return currentFPS - lastFPS; }
		void updateTime(GLboolean showData) {
			currentTime = glfwGetTime();
			currentFPS++;
			if (currentTime - lastTime >= 1.0) {
				ms_per_frame = 1000.0 / double(currentFPS);
				totalFPS += currentFPS;
				if (showData) {
					std::cout << "[" << (int)currentTime << " SECONDS] "
							  << "[" << ms_per_frame << " MS/FRAME] " 
							  << "[" << currentFPS << " FPS] "
							  << "[" << getDifferential() << " DIFFERENTIAL] "
						      << "[" << totalFPS << " TOTAL FRAMES] "
						      << "[" << delta_time << " DELTA TIME]" << std::endl;
				}
				lastFPS = currentFPS;
				currentFPS = 0;
				lastTime += 1.0;
			}
		}
	} Time;
	GLFWwindow* window;
	GLint width;
	GLint height;
	const char* title;
	World world;
	glm::highp_dvec2 mouse = glm::highp_dvec2(0.0,0.0);
	GLuint bufferID;
	GLuint bufferIndicesID;
public:
	static Camera camera;
	Application(const char* title);

	GLint getWidth() const;
	GLint getHeight() const;
	const char* getTitle() const;
	World getWorld() const;
	glm::highp_dvec2 getMousePosition() const;


	int init();
	void update();
	void cleanup();
};

