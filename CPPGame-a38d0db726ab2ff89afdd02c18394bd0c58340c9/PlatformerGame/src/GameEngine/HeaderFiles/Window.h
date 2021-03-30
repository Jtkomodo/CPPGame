#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cassert>
#include <unordered_map>

class Window {

public:
	


private:
	GLFWwindow* window;
	const GLFWvidmode* VidMode;
	int width, height,dh,dw; 
	

public:
	Window(int width, int height,const char name[]);

	GLFWwindow* getWindow();
	int getWidth();
	int getHeight();
	void Update();
	void Render();
	void clear();
	void Destroy();
	void setFullScreen(bool fullscreen,Camera &camera);
	boolean SHouldExit();
    static byte checkState(int key);



private:

	







};