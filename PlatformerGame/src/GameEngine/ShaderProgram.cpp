#include "ShaderProgram.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
//using namespace std;


ShaderProgram::ShaderProgram(std::string Name) {
	//cout << "file " << location << endl;
	std::string FILE = "src/Shaders/";
	
    std::string  vertexShader= ShaderProgram::LoadShader(FILE+Name+".vs");
	std::string  FragmentShader = ShaderProgram::LoadShader(FILE+Name+".fs");

	

}

ShaderProgram::~ShaderProgram()
{
	glDeleteShader(vs);
	glDeleteShader(fs);
}



std::string ShaderProgram::LoadShader(std::string path) {
	std::ifstream a(path);
	std::string line;
	std::stringstream stream;
	std::string returnstream;

	
	if (!a) {

		std::cout << "file : " << path << " not loaded" << std::endl;
	}
	else {
		while (getline(a, line)) {

			stream << line << '\n';


		}

	}
	returnstream=stream.str();

	return returnstream;

}
<<<<<<< HEAD

void ShaderProgram::Bind() {

	glUseProgram(program);


}

void ShaderProgram::UnBind() {

	glUseProgram(0);


}

int ShaderProgram::makeLocation(const char name[])
{
	int location = glGetUniformLocation(program,name);
	if (location ==-1) {

		std::cout << "uniform location " << name << "not used or not found" << std::endl;
		exit(0x75);
	}
	else {

		return location;
	}
}

void ShaderProgram::loadInt(int location, int value)
{
	glUniform1i(location,value);
}

void ShaderProgram::loadFloat(int location, float value)
{
	glUniform1f(location, value);
}

void ShaderProgram::loadVec2(int location, float x, float y)
{
	glUniform2f(location, x, y);
}

void ShaderProgram::loadvec4(int location, float r, float g, float b, float a)
{
	glUniform4f(location,r,g,b,a);
}

void ShaderProgram::loadMat4(int location, glm::mat4 matrix)
{
	glUniformMatrix4fv(location,1,GL_FALSE,&matrix[0][0]);
}


