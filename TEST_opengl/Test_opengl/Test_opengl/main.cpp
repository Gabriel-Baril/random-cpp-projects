#include "libs.h"

void framebuffer_resize_callback(GLFWwindow* window,int fbW, int fbH)
{
	glViewport(0,0,fbW,fbH);
}

bool loadShaders(GLuint program) 
{
	bool loadsuccess = true;
	char infoLog[512];
	GLint success;

	std::string temp = "";
	std::string src = "";

	std::ifstream in_file;

	// Vertex
	in_file.open("vertex_core.glsl");

	if (in_file.is_open()) {
		while (std::getline(in_file, temp));
		src += temp + "\n";
	}
	else 
	{
		std::cout << "ERROR::LOADSHADER::COULD_NOT_OPEN_VERTEX_FILE" << std::endl;
		loadsuccess = false;
	}

	in_file.close();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* vertCrs = src.c_str();
	glShaderSource(vertexShader, 1, &vertCrs, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) 
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::LOADSHADER::COULD_NOT_COMPILE_VERTEX_SHADER" << std::endl;
		std::cout << infoLog << std::endl;
		loadsuccess = false;
	}

	// Fragment

	temp = "";
	src = "";


	in_file.open("fragment_core.glsl");

	if (in_file.is_open()) {
		while (std::getline(in_file, temp));
		src += temp + "\n";
	}
	else
	{
		std::cout << "ERROR::LOADSHADER::COULD_NOT_OPEN_FRAGMENT_FILE" << std::endl;
		loadsuccess = false;
	}
		
	in_file.close();

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fragCrs = src.c_str();
	glShaderSource(fragmentShader, 1, &fragCrs, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::LOADSHADER::COULD_NOT_COMPILE_FRAGMENT_SHADER" << std::endl;
		std::cout << infoLog << std::endl;
		loadsuccess = false;
	}

	// Program

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::LOADSHADER::COULD_NOT_LINK_PROGRAM" << std::endl;
		std::cout << infoLog << std::endl;
	}

	// End
	glUseProgram(0);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return loadsuccess;
}

int main() {
	// INIT GLFW
	glfwInit();

	// CREATE WINDOW
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	int framebufferWidth = 0;
	int framebufferHeight = 0;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "TEST_OPENGL", NULL, NULL);

	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

	glfwMakeContextCurrent(window);

	// INIT GLEW

	glewExperimental = GL_TRUE;

	// ERROR
	if (glewInit() != GLEW_OK) {
		std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED" << std::endl;
		glfwTerminate();
	}

	// Shader Init
	GLuint core_program = 0;
	if (!loadShaders(core_program))
		glfwTerminate();

	// MAIN LOOP

	while (!glfwWindowShouldClose(window))
	{
		// UPDATE INPUT
		glfwPollEvents();

		// UPDATE

		// DRAW
		// CLEAR
		glClearColor(0.f,1.f,0.f,1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		// DRAW

		// END DRAW
		glfwSwapBuffers(window);
		glFlush();
	}


	// END PROGRAM
	glfwDestroyWindow(window);
	glfwTerminate();

	// Delete Program
	glDeleteProgram(core_program);

	return 0;
}