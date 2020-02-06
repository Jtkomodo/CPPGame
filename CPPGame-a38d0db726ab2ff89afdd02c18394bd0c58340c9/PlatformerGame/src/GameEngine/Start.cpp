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
#include "Window.h"
#include <Entity.h>
#include <chrono>
#include <objLoader.h>
#include <Light.h>


const int width = 640, height = 480;
double framecap = 1.0/60.0;//controls the frame limit 
glm::vec3 CamPosition,Position(0,0,-25),lightPosition(0);
int frames,FPS;

Window window(width, height, "Engine3d");


std::chrono::time_point<std::chrono::high_resolution_clock> Time1, Time2,lastFrame,now;
double timepassed, unproccesed, frameTime,DeltaT;
boolean canRender;


void Input() {
	window.Update();

	byte up = window.checkState(GLFW_KEY_UP);
	byte down = window.checkState(GLFW_KEY_DOWN);
	byte right = window.checkState(GLFW_KEY_RIGHT);
	byte left = window.checkState(GLFW_KEY_LEFT);
	byte w = window.checkState(GLFW_KEY_W);
	byte s = window.checkState(GLFW_KEY_S);
	byte c = window.checkState(GLFW_KEY_C);
	byte L = window.checkState(GLFW_KEY_L);

	float camspeed = 3;


	if (c > 0) {
		if (up > 0)CamPosition.y -= (DeltaT * camspeed);
		if (down > 0) CamPosition.y += (DeltaT * camspeed);
		if (left > 0) CamPosition.x += (DeltaT * camspeed);
		if (right > 0) CamPosition.x -= (DeltaT * camspeed);
		if (s > 0) CamPosition.z -= (DeltaT * camspeed);
		if (w > 0) CamPosition.z += (DeltaT * camspeed);
	}else if(L>0 ) {
		if (up > 0)lightPosition.y -= (DeltaT * camspeed);
		if (down > 0)lightPosition.y += (DeltaT * camspeed);
		if (left > 0)lightPosition.x += (DeltaT * camspeed);
		if (right > 0)lightPosition.x -= (DeltaT * camspeed);

		if (s > 0) lightPosition.z -= (DeltaT * camspeed);
		if (w > 0) lightPosition.z += (DeltaT * camspeed);

	}

	else{
	
		if (up > 0)Position.y -= (DeltaT * camspeed);
		if (down > 0)Position.y += (DeltaT * camspeed);
		if (left > 0)Position.x += (DeltaT * camspeed);
		if (right > 0)Position.x -= (DeltaT * camspeed);

	
	}

}



void fps() {
 
	canRender = false;
 Time2 = std::chrono::high_resolution_clock::now();
auto  time=std::chrono::duration<double> (Time2 - Time1);
 timepassed = time.count();
 
 unproccesed += timepassed;
 frameTime += timepassed;
 
 


 if (unproccesed >= framecap) {
	
	 now = std::chrono::high_resolution_clock::now();
	 auto timeP = std::chrono::duration<double>(lastFrame - now);
	 DeltaT = timeP.count();

	 canRender = true;
	 unproccesed -= framecap;
	 lastFrame = std::chrono::high_resolution_clock::now();
	 frames++;
 }
if (frameTime >= 1.0) {
	
	FPS = frames;
	frames = 0;
	frameTime = 0;
	frames = 0;
	std::cout << "FPS=" <<FPS << std::endl;

}



 

 Time1 = Time2;

 

}













void intFPS() {
	
	Time1 = std::chrono::high_resolution_clock::now();
	frames = 0;
	timepassed = 0;
	unproccesed = 0;
	frameTime = 0;



}









int main(int argc, char* argv[])
{
	
	
	std::string programName = "Shader";
	Camera cam(width,height,70,glm::vec3(0));
	
	ShaderProgram* a=new ShaderProgram(programName);//allocates the ShaderProgram to the heap for use later

	//Texture tex("texDragon");	Texture white("white");
	//objLoader f("dragon");


	Texture tex("texDragon");
	objLoader f("dragon");

	//gets all the shader locations ids so that we can load values into the GPU's uniforms 
	const int pLocation =a->makeLocation("projection");
	const int rtsLocation= a->makeLocation("rts");
	const int samplerLocation =a->makeLocation("sampler");
	const int LightPosLocation = a->makeLocation("LightPosition");
    const int LightCOlORLocation = a->makeLocation("lightColor");
	const int hasLocation = a->makeLocation("haslight");

	Model model(f.getverts(),f.getUVS(),f.getNormals(),f.getInds());//put in the data and the size of the arrays
  
	//Texture tex("stallTexture");
   Entity en(&model, glm::vec3(0,0,-2), glm::vec3(0),1);

   Light light(glm::vec3(0,0,-20),glm::vec3(1,1,1));
  
	a->Bind();//tells the GPU to use the specified shader program for rendering 

	//cam.setPosition(glm::vec2(100, 0));
	
		/* Loop until the user closes the window */
	

	//CamPosition = glm::vec3(0, 0, -20);
	intFPS();
	float rotx= 0;

//______________c__________________________________________________________________________________________
//                      GAME---LOOP                                                                      |

		while (!window.SHouldExit() && !(window.checkState(GLFW_KEY_ESCAPE)>0))
		{
			
			
			fps();
			
			if (canRender) {
				a->loadBool(hasLocation, true);
				Input();
			
				light.setPosition(lightPosition);
				cam.setPosition(CamPosition);

				tex.Bind(1);//this binds the texture data to the specified slot in texture2d


				glm::mat4 target = en.getTRS();

				en.setPosition(Position);
				en.setRotation(glm::vec3(0,rotx+=1,0));
				

				glm::vec3 lightposition=light.getPosition();
				glm::vec3 lightColor=light.getColor();

				glm::mat4 projection = cam.getProjection();//this is the projection matrix 
				a->loadMat4(pLocation, projection);//this loads in the projection matrix to the GPU for the world 
				a->loadvec3(LightPosLocation,lightposition.x,lightposition.y,lightposition.z);
				a->loadvec3(LightCOlORLocation, lightColor.x, lightColor.y, lightColor.z);
				a->loadMat4(rtsLocation, target);//this loads in the rotation translation and scale(RTS) matix to the GPU 
				a->loadInt(samplerLocation, 1);//this loads in the id for the texture2d sampler to pick the correct texture
				//m.printTest();

				en.Draw();//actually draws the model to the screen
				
				
				window.Render();
				window.clear();
			}
			/* Poll for and process events */
			
		}
//_______________________________________________________________________________________________________|
		printf("Closing---------------------------------------------------------");
        //glFlush();
		delete a;//deletes the shaderprogram from the heap 

		window.Destroy();
	
		std::exit;

	
	
	}
	
	

