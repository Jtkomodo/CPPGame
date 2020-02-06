#pragma once
#include <string.h>
#include <iostream>
#include <chrono>
#include "HeaderFiles/Vendor/glm/gtc/matrix_transform.hpp"
#include <vector>
#include <queue>
#include <unordered_map>

class objLoader {




public:




private:
	std::chrono::time_point<std::chrono::high_resolution_clock> Time1, Time2;
	std::vector<glm::vec3> verts;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3>  normals;
	std::vector<glm::uvec3> inds;



public:
	objLoader(std::string name);
	std::vector<glm::vec3> getverts();
	std::vector<glm::vec3> getNormals();
	std::vector<glm::vec2> getUVS();
	std::vector<glm::uvec3> getInds();
	

private:

	void readFile(std::string path);
	std::vector < glm::vec3> proccessVerts(std::queue<std::string> &,int);
	std::vector < glm::vec2> proccessUVS(std::queue<std::string>&,int);
	std::vector < glm::vec3> proccessNormals(std::queue<std::string> &,int);
	void proccessInds(std::queue<std::string>&,int&, std::unordered_map<int, std::string> &);
};