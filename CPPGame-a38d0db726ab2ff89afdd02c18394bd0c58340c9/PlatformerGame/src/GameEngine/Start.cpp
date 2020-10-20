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
#include <Terrain.h>


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
	if (window.checkState(GLFW_KEY_W) > 0) {
		camspeed * 10;
	  }


		if (up > 0)CamPosition.y -= (DeltaT * camspeed);
		if (down > 0) CamPosition.y += (DeltaT * camspeed);
		if (left > 0) CamPosition.x += (DeltaT * camspeed);
		if (right > 0) CamPosition.x -= (DeltaT * camspeed);
		if (s > 0) CamPosition.z -= (DeltaT * camspeed);
		if (w > 0) CamPosition.z += (DeltaT * camspeed);
	

	

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
	std::string tprograeName = "TerrainShader";
	Camera cam(width,height,70,glm::vec3(0));
	
	ShaderProgram* a=new ShaderProgram(programName);//allocates the ShaderProgram to the heap for use later
	ShaderProgram* terrainShader = new ShaderProgram(tprograeName);
	//Texture tex("texDragon");	Texture white("white");
	//objLoader f("dragon");


	Texture tex("texDragon");
	Texture grass("grass");
	objLoader f("dragon");

	Texture tex2("stallTexture");
	objLoader stall("stall");
	//gets all the shader locations ids so that we can load values into the GPU's uniforms 
	a->Bind();
	const int pLocation =a->makeLocation("projection");
	const int rtsLocation= a->makeLocation("rts");
	const int samplerLocation =a->makeLocation("sampler");
	const int LightPosLocation = a->makeLocation("LightPosition");
    const int LightCOlORLocation = a->makeLocation("lightColor");
	const int hasLocation = a->makeLocation("haslight");
	const int viewMatrixLocation = a->makeLocation("view");
	const int DampLocation = a->makeLocation("damper");
	const int ReflectLocation = a->makeLocation("reflectivity");
	terrainShader->Bind();
	const int TpLocation = terrainShader->makeLocation("projection");
	const int TrtsLocation = terrainShader->makeLocation("rts");
	const int TsamplerLocation = terrainShader->makeLocation("sampler");
	const int TLightPosLocation = terrainShader->makeLocation("LightPosition");
	const int TLightCOlORLocation = terrainShader->makeLocation("lightColor");
	const int ThasLocation = terrainShader->makeLocation("haslight");
	const int TviewMatrixLocation = terrainShader->makeLocation("view");
	const int TDampLocation = terrainShader->makeLocation("damper");
	const int TReflectLocation = terrainShader->makeLocation("reflectivity");
	

	Model model(f.getverts(),f.getUVS(),f.getNormals(),f.getInds());//put in the data and the size of the arrays
	Model model2(stall.getverts(), stall.getUVS(), stall.getNormals(), stall.getInds());//put in the data and the size of the arrays  
	//Texture tex("stallTexture");
   Entity en(model, glm::vec3(0,0,-2), glm::vec3(0),1,0,0);
   Entity en2(model2, glm::vec3(0, 0, -2), glm::vec3(0), 1, 10, 1);
   Light light(glm::vec3(2000,2000,2000),glm::vec3(1,1,1));
   Terrain t(0,0,tex);
   Model m = t.getModel();
   Entity terrain(m,glm::vec3(t.getGridx(),0,t.getGridZ()),glm::vec3(0),1,0,0);



	//a->Bind();//tells the GPU to use the specified shader program for rendering 

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
				a->Bind();
				a->loadBool(hasLocation, true);
				
				Input();
			
				light.setPosition(lightPosition);
				cam.setPosition(CamPosition);

				grass.Bind(1);//this binds the texture data to the specified slot in texture2d

				glm::mat4 view = cam.getView();
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
				a->loadMat4(viewMatrixLocation, view);
				a->loadFloat(DampLocation,en.getDamping());
				a->loadFloat(ReflectLocation, en.getReflect());
				//m.printTest();

				en.Draw();//actually draws the model to the screen
				
				
				terrainShader->Bind();
				terrainShader->loadBool(ThasLocation, true);
			    grass.Bind(1);//this binds the texture data to the specified slot in texture2d


			    target = terrain.getTRS();

				terrain.setPosition(Position + glm::vec3(0,20,0));
				terrain.setRotation(glm::vec3(0, 0, 0));


				 lightposition = light.getPosition();
				 lightColor = light.getColor();

				 projection = cam.getProjection();//this is the projection matrix 
				terrainShader->loadMat4(TpLocation, projection);//this loads in the projection matrix to the GPU for the world 
				terrainShader->loadvec3(TLightPosLocation, lightposition.x, lightposition.y, lightposition.z);
				terrainShader->loadvec3(TLightCOlORLocation, lightColor.x, lightColor.y, lightColor.z);
				terrainShader->loadMat4(TrtsLocation, target);//this loads in the rotation translation and scale(RTS) matix to the GPU 
				terrainShader->loadInt(TsamplerLocation, 1);//this loads in the id for the texture2d sampler to pick the correct texture
				terrainShader->loadFloat(TDampLocation, terrain.getDamping());
				terrainShader->loadFloat(TReflectLocation,terrain.getReflect());
				//m.printTest();

				terrain.Draw();//actually draws the model to the screen


				


				
				window.Render();
				window.clear();
			}
			/* Poll for and process events */
			
		}
//_______________________________________________________________________________________________________|
		//glFlush();
		delete a;//deletes the shaderprogram from the heap 

		window.Destroy();
		
		std::exit;

	
	
	}
	
	

