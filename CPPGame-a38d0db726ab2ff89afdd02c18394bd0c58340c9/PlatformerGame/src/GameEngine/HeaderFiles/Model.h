#pragma once
#include <iostream>

#include "HeaderFiles/Vendor/glm/gtc/matrix_transform.hpp"
#include <vector>
#include <GL\glew.h>
class Model
{
	//vars
	

public:
	
private:
	static int renderMode;
	unsigned int VertI,UVI,INDI,NORMALSI,drawCount,VAO_ID;
	
//functions

	public:
	//	Model(float verts[],float uv[],float ind[]);
		
		Model(std::vector<glm::vec3> verts, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals, std::vector<glm::uvec3> inds);
		
	    static void changeMode(int mode);
		void Draw();
	

	
	     ~Model();
private:
	  
	void enableAtrib();







};

