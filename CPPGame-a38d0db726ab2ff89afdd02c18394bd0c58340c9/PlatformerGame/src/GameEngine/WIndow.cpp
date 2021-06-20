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




void APIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
    GLenum severity, GLsizei length,
    const GLchar* msg, const void* data)
{
   const char* _source;
   const char* _type;
   const char* _severity;

    switch (source) {
    case GL_DEBUG_SOURCE_API:
        _source = "API";
        break;

    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        _source = "WINDOW SYSTEM";
        break;

    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        _source = "SHADER COMPILER";
        break;

    case GL_DEBUG_SOURCE_THIRD_PARTY:
        _source = "THIRD PARTY";
        break;

    case GL_DEBUG_SOURCE_APPLICATION:
        _source = "APPLICATION";
        break;

    case GL_DEBUG_SOURCE_OTHER:
        _source = "UNKNOWN";
        break;

    default:
        _source = "UNKNOWN";
        break;
    }

    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        _type = "ERROR";
        break;

    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        _type = "DEPRECATED BEHAVIOR";
        break;

    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        _type = "UDEFINED BEHAVIOR";
        break;

    case GL_DEBUG_TYPE_PORTABILITY:
        _type = "PORTABILITY";
        break;

    case GL_DEBUG_TYPE_PERFORMANCE:
        _type = "PERFORMANCE";
        break;

    case GL_DEBUG_TYPE_OTHER:
        _type = "OTHER";
        break;

    case GL_DEBUG_TYPE_MARKER:
        _type = "MARKER";
        break;

    default:
        _type = "UNKNOWN";
        break;
    }

    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        _severity = "HIGH";
        break;

    case GL_DEBUG_SEVERITY_MEDIUM:
        _severity = "MEDIUM";
        break;

    case GL_DEBUG_SEVERITY_LOW:
        _severity = "LOW";
        break;

    case GL_DEBUG_SEVERITY_NOTIFICATION:
        _severity = "NOTIFICATION";
        break;

    default:
        _severity = "UNKNOWN";
        break;
    }

    printf("%d:(%s, %s,%s)\n%s\n",
        id, _type, _severity, _source, msg);
}





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
	
    this->VidMode=glfwGetVideoMode(glfwGetPrimaryMonitor());
	if (glewInit() != GLEW_OK) {
		std::cout << "problem" << std::endl;
		exit(7);
	}
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
    //glCullFace(GL_BACK);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glfwSetKeyCallback(window,callback);
	glfwSwapInterval(0);

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(GLDebugMessageCallback, 0);
    dw = width;
    dh = height;
}

GLFWwindow* Window::getWindow()
{
	return window;
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

void Window::setFullScreen(bool fullscreen,Camera &camera)
{

    if (fullscreen) {

        glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, VidMode->width, VidMode->height, VidMode->refreshRate);// this allows fullscreen window .the value that actually changes if fullscreen is used is the second argument
    //	glViewport(0,0,width,height);	
        glViewport(0, 0,VidMode->width, VidMode->height); //this changes the view to the size of the monitor so that it won't be small
            //System.out.println(fullscreen);
        width = VidMode->width; height = VidMode->height;
        camera.setSize(width / 2.5f, height / 2.5f);
        glfwSwapInterval(1);
    }
    else {

        glfwSetWindowMonitor(window, 0, (this->VidMode->width - dw) / 2, (this->VidMode->height - dh) / 2, dw, dh,this->VidMode->refreshRate);
        glViewport(0, 0, dw, dh);
        width = dw; height = dh;
        camera.setSize(width, height);

        glfwSwapInterval(1);

    }


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


