#include "HeaderFiles\Window.h"
#include <GL/glew.h>
#include <glfw3.h>
#include <iostream>
#include <string>




Window::Window(const char name[],int width,int height) {
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
	

	/* Initialize the library */
	if (!glfwInit()) {
		exit(-1);
	}
	/* Create a windowed mode window and its OpenGL context */

	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(1);
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "problem" << std::endl;
		exit(7);
	}

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//allow gfwKeycallbacks for Callback

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

}


void Window::CloseProgram() {


	glfwTerminate();



}

boolean Window::IsClosed() {
	return glfwWindowShouldClose(window);

}
void Window::Update() {

	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();

}
