#pragma once
#include <GL/glew.h>
#include <glfw3.h>
#include <Windows.h>
#include <iostream>
#include "HeaderFiles/Model.h"
#include "HeaderFiles/ShaderProgram.h"
#include <string>



class Window
{
public:



private:

	GLFWwindow* window;

public:

	Window(const char name[],int width,int height);
	void Update();
	void CloseProgram();
	boolean IsClosed();

private:







};

