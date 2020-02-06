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
	int width, height; 
	

public:
	Window(int width, int height,const char name[]);

	GLFWwindow& getWindow();
	int getWidth();
	int getHeight();
	void Update();
	void Render();
	void clear();
	void Destroy();
	boolean SHouldExit();
    static byte checkState(int key);



private:

	







};