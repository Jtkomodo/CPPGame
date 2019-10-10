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

objLoader::~objLoader()
{
	

}

void objLoader::readFile(std::string path) {

	std::ifstream a(path);
	std::string line;
	//std::stringstream stream;
	std::string returnstream;
	int av=0;
	int auv=0;
	int an=0;
	int Aind=0;
	int amInd = 0;
	int amInd2 = 0;

	int lines = 0;
	std::unordered_map<int,float*> VertValues;
	std::unordered_map<int, float*> UVValues;
	std::unordered_map<int, float*> NormalValues;
	std::unordered_map<int, int> fs1;
	std::unordered_map<int, int> fs2;
	std::unordered_map<int, int> fs3;
	std::unordered_map<std::string,int> fstring;
	std::unordered_map<int, std::string> fstring2;
	std::unordered_map<int, int> fArray;
	std::unordered_map<std::string, int>::const_iterator f;
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
          while (getline(a, line)) {
			  switch(line[0]) {
			 
			  case 'v':
				  
				  
				  
				  if (line[1] == 't') {
					  n = line.find(" ");//n returns a position of wwhere the space is at 
					  line = line.substr(n + 1);//i delete everything in the strig before the space including the space


					  float value1 = stof(line, &n);
					  line = line.substr(n);
					  float value2 = stof(line, &n);

					  float* values3 = new float[2]{
						  value1,1 - value2 };

					  UVValues[auv] = values3;



					  auv++;

				  }
				  else if(line[1]==' ') {
					  n = line.find(" ");//n returns a position of wwhere the space is at 
					  line = line.substr(n + 1);//i delete everything in the strig before the space including the space

					  float value1 = stof(line, &n);
					  line = line.substr(n);
					  float value2 = stof(line, &n);
					  line = line.substr(n);
					  float value3 = stof(line, &n);


					  float* values4 = new float[3]{
					  value1,value2,value3 };

					  VertValues[av] = values4;


					  av++;

				  }
				  else if (line[1] =='n') {

					  n = line.find(" ");//n returns a position of wwhere the space is at 
					  line = line.substr(n + 1);//i delete everything in the strig before the space including the space

					  float value1 = stof(line, &n);
					  line = line.substr(n);
					  float value2 = stof(line, &n);
					  line = line.substr(n);
					  float value3 = stof(line, &n);

					  float* values = new float[3]{
					  value1,value2,value3 };

					  NormalValues[an] = values;


					  an++;

				  }




                  break;
			  case 'f':



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




				  fArray[amInd2] = value1;
				  fArray[amInd2 + 1] = value2;
				  fArray[amInd2 + 2] = value3;


				  // stream <<" "<<value1<<" "<<" "<<value2<<" "<<" "<<value3<<"\n";
				  amInd++;
				  amInd2 = amInd * 3;





				  break;
			  default:break;

			  }
			
		
			lines++;
		}
		
		objLoader::size4 = amInd * 3;
		objLoader::size1 = Aind*3;
		objLoader::size2 = Aind*2;
		objLoader::size3 = Aind*3;


		std::cout << "amount of Lines in File:" << lines << "\n";
		std::cout << "amount of Verts:" << size1 << "\n";
		std::cout << "amount of UVS:" << size2 << "\n";
		std::cout << "amount of Normals:" << size3 << "\n";
		std::cout << "amount of Inds:" << size4 << "\n";
		std::cout << "amout of triangles:" << Aind<<"\n";
		inds = new int[size4];
		verts=new float[size1];
		uvs = new float[size2];
		normals = new float[size3];
	
		std::string::size_type n;
		std::string s2, s3;
		float* v;
		

		
		
		for (int i = 0; i < size4; i += 3) {
			inds[i] = fArray[i];
			inds[i + 1] = fArray[i + 1];
			inds[i + 2] = fArray[i + 2];
		}


	



		for (int i = 0; i < Aind; i++) {
			std::string s = fstring2[i];


			int value1 = stoi(s, &n);
			s2 = s.substr(n + 1);
			int value2 = stoi(s2, &n);
			s3 = s2.substr(n + 1);
			int value3 = stoi(s3, &n);
			value1--;
			v = new float[3];
			v = VertValues[value1];
		
			int c = i * 3;
			int c2 = i * 2;

			verts[c] =v[0];
			verts[c+1] =v[1];
		    verts[c+2] = v[2];
			
			v = new float[2];
			value2--;
			v =UVValues[value2];
			uvs[c2] = v[0];
			uvs[c2+ 1] = v[1];
			

			v = new float[3];
			value3--;
			v =NormalValues[value3];
			normals[c] = v[0];
			normals[c+ 1] = v[1];
			normals[c + 2] = v[2];

		
		

			



		}


	

	





	//	returnstream = stream.str();

	//	std::cout << returnstream << std::endl;
		
	}




}

float* objLoader::getverts()
{
	return objLoader::verts;
}

float* objLoader::getNormals()
{
	return objLoader::normals;
}

float* objLoader::getUVS()
{
	return objLoader::uvs;
}

int* objLoader::getInds()
{
	return objLoader::inds;
}

int objLoader::getVertSize()
{
	return objLoader::size1;
}

int objLoader::getNormSize()
{
	return objLoader::size3;
}

int objLoader::getindSize()
{
	return objLoader::size4;
}

int objLoader::getUvSize()
{
	return objLoader::size2;
}
