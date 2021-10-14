#include "Application.h"

Camera Application::camera = Camera(2.0f, (float) WINDOW_WIDTH / WINDOW_HEIGHT, 0.1f, 100.0f);
Application::Application(const char* title)
{
	this->width = WINDOW_WIDTH;
	this->height = WINDOW_HEIGHT;
	this->title = title;
	this->world = World();
}

GLint Application::getWidth() const
{
	return this->width;
}

GLint Application::getHeight() const
{
	return this->height;
}

const char * Application::getTitle() const
{
	return this->title;
}

World Application::getWorld() const
{
	return this->world;
}

glm::highp_dvec2 Application::getMousePosition() const
{
	return this->mouse;
}

int Application::init()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "FAILED TO INITIALIZE GLFW" << std::endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}


	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, true);
	glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(this->width, this->height, title, NULL, NULL);


	if (!Application::window)
	{
		std::cout << "FAILED TO CREATE WINDOW" << std::endl;
		system("PAUSE");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		std::cout << "FAILED TO INITIALIZE GLEW" << std::endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}

	glewExperimental = GL_TRUE;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);

	world = World();

	return EXIT_SUCCESS;
}

Shader shader = Shader();

float fov = 10;
float angle = 0;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_W)
		Application::camera.moveForward();
	if (key == GLFW_KEY_S)
		Application::camera.moveBackward();
	if (key == GLFW_KEY_D)
		Application::camera.moveRight();
	if (key == GLFW_KEY_A)
		Application::camera.moveLeft();
	if (key == GLFW_KEY_Q)
		Application::camera.moveUp();
	if (key == GLFW_KEY_E)
		Application::camera.moveDown();
}


void Application::update()
{
	GLfloat blockVertices[] =
	{
		0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // NORTH
		0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 1.0f, // NORTH
		2.0f, 0.0f, 2.0f, 0.0f, 0.0f, 1.0f, // NORTH
		2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // NORTH

		0.0f, -2.0f, 0.0f, 1.0f, 0.0f, 0.0f, // SOUTH
		0.0f, -2.0f, 2.0f, 1.0f, 0.0f, 0.0f, // SOUTH
		2.0f, -2.0f, 2.0f, 1.0f, 0.0f, 0.0f, // SOUTH
		2.0f, -2.0f, 0.0f, 1.0f, 0.0f, 0.0f, // SOUTH

		2.0f, -2.0f, 2.0f, 1.0f, 0.0f, 1.0f, // EST
		2.0f, 0.0f, 2.0f, 1.0f, 0.0f, 1.0f,  // EST
		2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,  // EST
		2.0f, -2.0f, 0.0f, 1.0f, 0.0f, 1.0f, // EST

		0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,  // OUEST
		0.0f, 0.0f, 2.0f, 1.0f, 1.0f, 0.0f,  // OUEST
		0.0f, -2.0f, 2.0f, 1.0f, 1.0f, 0.0f, // OUEST
		0.0f, -2.0f, 0.0f, 1.0f, 1.0f, 0.0f, // OUEST

		0.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f,  // FRONT
		2.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f,  // FRONT
		2.0f, -2.0f, 2.0f, 0.0f, 1.0f, 0.0f, // FRONT
		0.0f, -2.0f, 2.0f, 0.0f, 1.0f, 0.0f, // FRONT

		0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // BACK
		2.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // BACK
		2.0f, -2.0f, 0.0f, 0.0f, 1.0f, 1.0f, // BACK
		0.0f, -2.0f, 0.0f, 0.0f, 1.0f, 1.0f  // BACK
	};

	GLushort blockIndices[] =
	{
		0,1,2,    // NORTH
		0,2,3,    // NORTH

		4,6,5,    // SOUTH
		4,7,6,	  // SOUTH

		8,10,9,   // EST
		8,11,10,  // EST

		12,14,13, // OUEST
		12,15,14, // OUEST

		16,19,18, // FRONT
		16,18,17, // FRONT

		20,22,23, // BACK
		20,21,22  // BACK
	};

	glGenBuffers(1,&bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(blockVertices), blockVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 3));

	glGenBuffers(1, &bufferIndicesID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferIndicesID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(blockIndices), blockIndices, GL_STATIC_DRAW);

	shader.init("shaderVertex.txt", "shaderFragment.txt");
	shader.use();

	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPos(window, width / 2, height / 2);

	GLuint fullTransformationUniformLocation = glGetUniformLocation(shader.getProgram(), "fullTransformMatrix");

	glm::mat4 fullTransformMatrix;
	glm::mat4 projectionMatrix = glm::perspective(camera.getFOV(), camera.getAspect(), camera.getNearPlaneDist(), camera.getFarPlaneDist());
	glm::mat4 viewProjectionMatrix;

	this->world.generate();

	while (!glfwWindowShouldClose(Application::window))
	{
		Time.updateTime(GL_TRUE); // DO NOT TOUCH !!
		glfwGetFramebufferSize(Application::window, &this->width, &this->height);
		glViewport(0, 0, this->width, this->height);
		glfwGetCursorPos(this->window, &this->mouse.x, &this->mouse.y);
		camera.setAspect((float)this->width/this->height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (mouse.x > 0 && mouse.x < width && mouse.y > 0 && mouse.y < height)
			Application::camera.mouseUpdate(mouse);

		//float t_x = 2 * (float)mouse.x / (float)width - 1;
		//float t_y = 2 * (float)mouse.y / (float)height - 1;
		//std::cout << "(" << t_x << "," << t_y << ")" << std::endl;


		viewProjectionMatrix = projectionMatrix * camera.getWorldToViewMatrix();

		Renderer::render(this->world.getChunks(), fullTransformationUniformLocation, viewProjectionMatrix);

		glfwSwapBuffers(window); // Swap front and back buffers
		glfwPollEvents(); // Poll for and process events
		Time.delta_time = (glfwGetTime() - Time.currentTime) * 1000; // DO NOT TOUCH !!
	}
}

void Application::cleanup()
{
	shader.free();
	glDeleteBuffers(1, &bufferID);
	glDeleteBuffers(1, &bufferIndicesID);
	glfwDestroyWindow(this->window);
	glfwTerminate();
}

