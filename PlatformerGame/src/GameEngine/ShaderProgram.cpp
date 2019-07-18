#include "HeaderFiles\ShaderProgram.h"
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
//deconstructor

