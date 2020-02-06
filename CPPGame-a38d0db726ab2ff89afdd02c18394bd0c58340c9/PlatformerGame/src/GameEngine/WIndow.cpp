#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Windows.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "HeaderFiles/Model.h"
#include "HeaderFiles/ShaderProgram.h"
#include <string>
#include "HeaderFiles/Texture.h"
#include "HeaderFiles/Vendor/glm/gtc/matrix_transform.hpp"
#include "Camera.h"
#include "MatrixMath.h"
#include <Entity.h>
#include <iostream>
#include <cassert>
#include <unordered_map>

#include "HeaderFiles/Window.h"

static std::unordered_map<int, boolean> keys;
static std::unordered_map<int, boolean> lastkeys;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key != -1) {
		keys[key] = (action != GLFW_RELEASE);
	}
	

}
auto callback=key_callback;

Window::Window(int width, int height, const char name[]) {
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
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	
	//glCullFace(GL_BACK);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetKeyCallback(window,callback);
	glfwSwapInterval(0);
}

GLFWwindow& Window::getWindow()
{
	return *window;
}

int Window::getWidth()
{
	return width;
}

int Window::getHeight()
{
	return height;
}




void Window::Render() {///swap buffers


	glfwSwapBuffers(window);//swaps the last screen buffer with the current one so that the image can be viewed 
}
void Window::Update() {
	glfwPollEvents();//this polls all the input 
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//this polls all the input 
}
boolean Window::SHouldExit() {

	return glfwWindowShouldClose(window);
}
void Window::Destroy() {
	glfwDestroyWindow(window);
	
}


byte Window::checkState(int key) {
	
	byte state;
	boolean now=keys[key];
	boolean last = lastkeys[key];

	if (last==true) {
		if (now==true) {
			state = 3;
		}
		else {
			state = 2;
		}

	}


	else {
		if (now==true) {
			state = 1;
		}
		else {
			state = 0;
		}

	}


	lastkeys[key] = now;
	return state;


}


