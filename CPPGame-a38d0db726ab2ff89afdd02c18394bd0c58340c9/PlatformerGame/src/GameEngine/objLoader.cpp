#include "objLoader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#include <cassert>
#include <chrono>

/*
to do change this to use std::vector instead of arrays




*/


objLoader::objLoader(std::string name) {
	Time1= std::chrono::high_resolution_clock::now();
	std::string FILE = "src/res/Objs/";
	std::string End = ".obj";

	std::string Path = FILE + name + End;
	
	readFile(Path);
	Time2 = std::chrono::high_resolution_clock::now();
	auto  time = std::chrono::duration_cast<std::chrono::duration<double>>(Time2 - Time1);
	double timepassed = time.count();
	
	std::cout << "Took " <<timepassed << " seconds to load " << name << " Model\n";

}


void objLoader::readFile(std::string path) {

	std::ifstream a;
	std::string line;
	//std::stringstream stream;
	
	
	int Aind=0;
	int amInd = 0;
	int at = 0, av = 0, an=0;


	int lines = 0;
	std::vector<glm::vec3> VertValues;
	std::vector<glm::vec2> UVValues;
	std::vector<glm::vec3> NormalValues;
	
	std::queue<std::string> vertStrings;
	std::queue<std::string> uvStrings;
	std::queue<std::string> normalStrings;
	std::queue<std::string>  indStrings;
	
	
	std::unordered_map<int, std::string> fstring2;
	std::unordered_map<std::string, int>::const_iterator f;
	a.open(path);
	
	std::string string1;
	std::string string2;
	std::string string3;
	std::string string4;

	std::string::size_type n;
	if (!a) {
		
		std::cout << "ERROR 404  file : " << path << " not loaded" << std::endl;
		std::exit(404);
	}
	else {
		auto Time1 = std::chrono::high_resolution_clock::now();
         while (getline(a, line)) {
			  switch(line[0]) {
			 
			  case 'v':
				  
				  
				  
				  if (line[1] == 't') {
					 

					  uvStrings.push(line);
					  at++;

				  }
				  else if(line[1]==' ') {
				
					  
					  vertStrings.push(line);
					  av++;
				  }
				  else if (line[1] =='n') {

					  normalStrings.push(line);
					  an++;
					 

				  }




                  break;
			  case 'f':





				  indStrings.push(line);


				  break;
			

			  }
			
		
			lines++;
		}



		

	









		a.close();
		auto Time2 = std::chrono::high_resolution_clock::now();
		auto  time = std::chrono::duration_cast<std::chrono::duration<double>>(Time2 - Time1);
		double timepassed = time.count();

		std::cout << "Took " << timepassed << " seconds to read file\n";

		
		
		std::string::size_type n;
		std::string s2, s3;
	
		

		
		
		UVValues = proccessUVS(uvStrings,at);
		VertValues = proccessVerts(vertStrings,av);
		NormalValues = proccessNormals(normalStrings,an);
		proccessInds(indStrings,Aind,fstring2);
		
		
		int size4 = inds.size();
		int size1 = VertValues.size();
		int size2 = UVValues.size();
		int size3 = NormalValues.size();


		std::cout << "amount of Lines in File:" << lines << "\n";
		std::cout << "amount of Verts:" << size1 << "\n";
		std::cout << "amount of UVS:" << size2 << "\n";
		std::cout << "amount of Normals:" << size3 << "\n";
		std::cout << "amount of Inds:" << size4 << "\n";
		std::cout << "amout of triangles:" << Aind << "\n";
		Time1 = std::chrono::high_resolution_clock::now();

		for (int i = 0; i <Aind; i++) {
			std::string s = fstring2[i];


			int value1 = stoi(s, &n)-1;
			s2 = s.substr(n + 1);
			int value2 = stoi(s2, &n)-1;
			s3 = s2.substr(n + 1);
			int value3 = stoi(s3, &n)-1;
	
	
		
			

			verts.push_back(VertValues[value1]);
			uvs.push_back(UVValues[value2]);
			normals.push_back(NormalValues[value3]);
			
		
		

			



		}

		 Time2 = std::chrono::high_resolution_clock::now();
		  time = std::chrono::duration_cast<std::chrono::duration<double>>(Time2 - Time1);
		timepassed = time.count();

		std::cout << "Took " << timepassed << " seconds to make arrays\n";


	

	





	//	returnstream = stream.str();

	//	std::cout << returnstream << std::endl;
		
	}




}

std::vector<glm::vec3> objLoader::proccessVerts(std::queue<std::string> strings,int size)
{
	auto Time1 = std::chrono::high_resolution_clock::now();
	std::vector<glm::vec3> VertValues;
	std::string::size_type n;
	std::string line;

	
	for (int i = 0; i < size;i++) {
	
	 line = strings.front();
		
	n = line.find(" ");//n returns a position of wwhere the space is at 
	line = line.substr(n + 1);//i delete everything in the strig before the space including the space

	float x = stof(line, &n);
	line = line.substr(n);
	float y = stof(line, &n);
	line = line.substr(n);
	float z = stof(line, &n);


	VertValues.push_back(glm::vec3(x, y, z));
	strings.pop();
	

}
	auto Time2 = std::chrono::high_resolution_clock::now();
	auto  time = std::chrono::duration_cast<std::chrono::duration<double>>(Time2 - Time1);
	double timepassed = time.count();

	std::cout << "Took " << timepassed << " seconds to proccess verts \n";
return VertValues;
}

std::vector<glm::vec2> objLoader::proccessUVS(std::queue<std::string> strings,int size)
{
	auto Time1 = std::chrono::high_resolution_clock::now();
	std::vector<glm::vec2> UVValues;
	std::string::size_type n;
	
	std::string line;

	for(int i=0;i<size;i++) {
		
		
    line = strings.front();
	n = line.find(" ");//n returns a position of wwhere the space is at 
	line = line.substr(n + 1);//i delete everything in the strig before the space including the space


	float u = stof(line, &n);
	line = line.substr(n);
	float v = stof(line, &n);


	UVValues.push_back(glm::vec2(u, 1 - v));
	strings.pop();
}
	auto Time2 = std::chrono::high_resolution_clock::now();
	auto  time = std::chrono::duration_cast<std::chrono::duration<double>>(Time2 - Time1);
	double timepassed = time.count();

	std::cout << "Took " << timepassed << " seconds to proccess uvs \n";
	return UVValues;
}

std::vector<glm::vec3> objLoader::proccessNormals(std::queue<std::string> strings,int size)
{
	auto Time1 = std::chrono::high_resolution_clock::now();
	std::vector<glm::vec3> NormalValues;
	std::string::size_type n;
	std::string line;

	for (int i = 0; i < size;i++) {

		line = strings.front();
		n = line.find(" ");//n returns a position of wwhere the space is at 
		line = line.substr(n + 1);//i delete everything in the strig before the space including the space

		float x = stof(line, &n);
		line = line.substr(n);
		float y = stof(line, &n);
		line = line.substr(n);
		float z = stof(line, &n);



		NormalValues.push_back(glm::vec3(x, y, z));
		strings.pop();
	}
	auto Time2 = std::chrono::high_resolution_clock::now();
	auto  time = std::chrono::duration_cast<std::chrono::duration<double>>(Time2 - Time1);
	double timepassed = time.count();

	std::cout << "Took " << timepassed << " seconds to proccess normals \n";
	return NormalValues;
}

void objLoader::proccessInds(std::queue<std::string> strings, int& Aind, std::unordered_map<int, std::string>& fstring2)
{
	auto Time1 = std::chrono::high_resolution_clock::now();
	std::vector<glm::vec3> NormalValues;
	std::string::size_type n;
	std::string line;


	std::unordered_map<std::string, int>  fstring;
	std::unordered_map<std::string, int>::const_iterator f;

	std::string string1;
	std::string string2;
	std::string string3;
	std::string string4;
	while(strings.size()!=0 ){
	
		line = strings.front();
		
		n = line.find(" ");//n returns a position of wwhere the space is at 
	line = line.substr(n + 1);//i delete everything in the strig before the space including the space


	//valu1
	n = line.find(" ");
	string1 = line.substr(0, n);
	f = fstring.find(string1);
	int value1;

	if (f == fstring.end()) {
		value1 = Aind;
		fstring[string1] = Aind;
		fstring2[Aind] = string1;
		Aind++;
	}
	else {
		value1 = fstring[string1];
	}
	//value 2


	string4 = line.substr(n + 1);
	n = string4.find(" ");
	string2 = string4.substr(0, n);
	f = fstring.find(string2);
	int value2;
	if (f == fstring.end()) {
		value2 = Aind;
		fstring[string2] = Aind;
		fstring2[Aind] = string2;
		Aind++;
	}
	else {
		value2 = fstring[string2];
	}
	//value3


	string3 = string4.substr(n + 1);
	n = string3.find(" ");
	string3 = string3.substr(0, n);
	f = fstring.find(string3);
	int value3;
	if (f == fstring.end()) {
		value3 = Aind;
		fstring[string3] = Aind;
		fstring2[Aind] = string3;
		Aind++;
	}
	else {
		value3 = fstring[string3];
	}




	inds.push_back(glm::uvec3(value1, value2, value3));
	strings.pop();
}
	auto Time2 = std::chrono::high_resolution_clock::now();
	auto  time = std::chrono::duration_cast<std::chrono::duration<double>>(Time2 - Time1);
	double timepassed = time.count();

	std::cout << "Took " << timepassed << " seconds to proccess inds \n";
}

std::vector<glm::vec3> objLoader::getverts()
{
	return objLoader::verts;
}

std::vector<glm::vec3> objLoader::getNormals()
{
	return objLoader::normals;
}

std::vector<glm::vec2> objLoader::getUVS()
{
	return objLoader::uvs;
}

std::vector<glm::uvec3> objLoader::getInds()
{
	return objLoader::inds;
}

