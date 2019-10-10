#include "HeaderFiles\ShaderProgram.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <GL\glew.h>
//using namespace std;


ShaderProgram::ShaderProgram(std::string& Name) {
	
	
	//cout << "file " << location << endl;
	std::string FILE = "src/Shaders/";
	program = glCreateProgram();
	std::string  vertexShader= ShaderProgram::LoadShader(FILE+Name+".vert");//string contaning sourcce code
	std::string  FragmentShader = ShaderProgram::LoadShader(FILE + Name + ".frag");//string contaning source code
	vs = glCreateShader(GL_VERTEX_SHADER);
	fs= glCreateShader(GL_FRAGMENT_SHADER);
	const char* Vssrc= vertexShader.c_str();//this is a pionter to where the source code is in memory
	const char* Fssrc = FragmentShader.c_str();//this is a pionter to where the source code is in memory

	int status=0;//this is my status flag variable it will tell the compile status
	glShaderSource(vs,1,&Vssrc,NULL);
	glCompileShader(vs);
	glShaderSource(fs, 1, &Fssrc, NULL);
	glCompileShader(fs);

	glGetShaderiv(vs,GL_COMPILE_STATUS,&status);
	if (status != GL_TRUE) {
		
		
		int log_length = 0;
		

		glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &log_length);
		char* Emessage = new char[log_length];
		
		glGetShaderInfoLog(vs, log_length, &log_length, Emessage);
		std::cout << "compile of vs shader failed(code 8) :\n" << Emessage << std::endl;
		delete[] Emessage;
		exit(vsnotCompiled);
	
	}
	
	glGetShaderiv(fs, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {


		int log_length = 0;

		glGetShaderiv(fs,GL_INFO_LOG_LENGTH,&log_length);
		char *Emessage2=new char[log_length];
		glGetShaderInfoLog(fs, log_length, &log_length,Emessage2);
		std::cout << "compile of fs shader failed(code 9) :\n" << Emessage2 << std::endl;
		delete[] Emessage2;
		exit(fsnotCompiled);
	
	}

	glAttachShader(program,vs);
	glAttachShader(program, fs);
	//glDeleteShader(vs);
	//glDeleteShader(fs);

	glBindAttribLocation(program, 0, "vertices");
	glBindAttribLocation(program, 1, "textureCoords");
	glBindAttribLocation(program, 2, "normals");



	int statusofLink=0;
	int statusofValidate=0;
	glLinkProgram(program);
	glGetProgramiv(program,GL_LINK_STATUS,&statusofLink);
	if (statusofLink != GL_TRUE) {
		
		int log_length = 0;

		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
		char* Emessage2 = new char[log_length];
		glGetShaderInfoLog(fs, log_length, &log_length, Emessage2);
		glGetProgramInfoLog(program, log_length, &log_length, Emessage2);

		std::cout << "link of program failed:" << std::endl;
	}
	glValidateProgram(program);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &statusofValidate);
	if (statusofLink != GL_TRUE) {

		int log_length = 0;

		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
		char* Emessage2 = new char[log_length];
		glGetShaderInfoLog(fs, log_length, &log_length, Emessage2);
		glGetProgramInfoLog(program, log_length, &log_length, Emessage2);

		std::cout << "Validation of program failed:" << std::endl;
	}

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
	returnstream = stream.str();

	return returnstream;

}

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

void ShaderProgram::loadBool(int location, bool value)
{
	glUniform1i(location, value);
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

void ShaderProgram::loadvec4(int location, float x, float y, float z, float w)
{
	glUniform4f(location,x,y,z,w);
}
void ShaderProgram::loadMat4(int location,glm::mat4 matrix) {

	glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);

}

void ShaderProgram::loadvec3(int location, float x, float y, float z)
{
	glUniform3f(location, x, y, z);
}
