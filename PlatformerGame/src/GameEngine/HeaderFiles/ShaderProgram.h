#pragma once
#include <string>
#include "glm/gtc/matrix_transform.hpp"


class ShaderProgram {
private:


public:



private:
	

public:
<<<<<<< HEAD
	ShaderProgram(std::string& filename);
	~ShaderProgram();
	void Bind();
	void UnBind();
	int makeLocation(const char  name[]);
	void loadInt(int location,int value);
	void loadFloat(int location, float value);
	void loadVec2(int location, float x, float y);
	void loadvec4(int location,float x,float y,float z,float w);
	void loadMat4(int location,glm::mat4 matrix);
=======
	ShaderProgram(std::string filename);
	std::string LoadShader(std::string path);
	
>>>>>>> parent of a38d0db... added a whole lot

};