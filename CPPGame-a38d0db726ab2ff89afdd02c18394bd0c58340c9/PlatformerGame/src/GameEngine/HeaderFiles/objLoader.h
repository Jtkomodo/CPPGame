#pragma once
#include <string.h>
#include <iostream>


class objLoader {




public:




private:

	float* verts;
	float* uvs;
	float* normals;
	int* inds;
	int size1, size2, size3, size4;



public:
	objLoader(std::string name);
	~objLoader();

	float* getverts();
	float* getNormals();
	float* getUVS();
	int* getInds();
	int getVertSize();
	int getNormSize();
	int getindSize();
	int getUvSize();

private:

	void readFile(std::string path);
	//void HandleVerts(std::string verts);
	//void HandleUVs(std::string uvs);
	//void HandleNorms(std::string norms);
	//void HandleFaces(std::string faces);
	



};