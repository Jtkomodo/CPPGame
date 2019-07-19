#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Windows.h>
#include <iostream>
#include "HeaderFiles/Model.h"
#include "HeaderFiles/ShaderProgram.h"
#include <string>

int main(int argc, char* argv[])
{



	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit()) {
		return -1;
	}
	/* Create a windowed mode window and its OpenGL context */

	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	window = glfwCreateWindow(640, 480, "PLatformer", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return 1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "problem" << std::endl;
		return 7;
	}
	float verts[8] = {
		-0.5f,0.5f,
	    0.5f,0.5f,
		0.5f,-0.5f,
		-0.5f,-0.5f

	};



	//unsigned int vert;
	
	std::string programName = "Shader";
	
	
    

	ShaderProgram* a=new ShaderProgram(programName);


	a->Bind();


	
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			
			//m.printTest();

		





			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
		//glFlush();
		delete a;
		glfwTerminate();
		
		std::exit;

	
	
	}
