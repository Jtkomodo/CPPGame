#include <GL/glew.h>
#include <glfw3.h>
#include <Windows.h>
#include "HeaderFiles\Window.h"
#include <iostream>
#include "HeaderFiles/Model.h"
#include "HeaderFiles/ShaderProgram.h"
#include <string>
#include "HeaderFiles/Texture.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Camera.h"
#include "MatrixMath.h"
#include"TIleData.h"

int main(int argc, char* argv[])
{
	float width = 640, height = 480;




	Window window("Platformer",width,height);
    float verts[] = {
		-0.5f,0.5f,,0,//0,1
	    0.5f,0.5f,0,//1,1
		0.5f,-0.5f,0,//1,0
		-0.5f,-0.5f,0,//0,0


	};

	float uv[] = {
		 0,0,//top left
	0.25f,0,//top right
	0.25f,0.25f,//bottom right
	0,0.25f

	};

	int ind[] = {
     0,1,2,
	 2,3,0
	};


	//unsigned int vert;
	Camera cam(width, height);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "problem" << std::endl;
		return 7;
	}
	float verts[6] = {
		0.5f,0.5f,
		0,0,
		-0.5f,-0.5f

	};
	//unsigned int vert;
	Model m(verts);

	std::string programName = "Shader";
	
	ShaderProgram Shader(programName);//my shader program
	Shader.Bind();
	Texture tex("src/res/Textures/newsprite.png");

	Model m(verts,TIleData::Grass.getValue(),ind),8,8,6;
	int samplerLocation=Shader.makeLocation("sampler");
	int projectionLocation = Shader.makeLocation("projection");
	int  RTSLocation = Shader.makeLocation("rts");
	//int colorLocation = Shader.makeLocation("color");
	
	


	Shader.loadInt(samplerLocation,1);
	
	//Shader.loadvec4(colorLocation, 1, 1, 1, 1);
	

    

	ShaderProgram* a=new ShaderProgram(programName);



		/* Loop until the user closes the window */
		while (!window.IsClosed())//this returns wether i closed the window or not
		{
		
			tex.Bind(1);
			
			glm::mat4 rts = getmatrix(glm::vec2(64, 0), 0, 64);
			

			Shader.loadMat4(projectionLocation, cam.getProjection());

			Shader.loadMat4(RTSLocation, rts);
			m.Draw();
		

			Shader.loadMat4(projectionLocation, cam.getProjection());
			rts = getmatrix(glm::vec2(0, 0), 0, 64);

			Shader.loadMat4(RTSLocation, rts);
			m.Draw();
			
             
		
		


			window.Update();//udates the window by swaping buffers and polling for events
		}
		//glFlush();
	
	
		window.CloseProgram();
		std::exit;

	
	
	}
