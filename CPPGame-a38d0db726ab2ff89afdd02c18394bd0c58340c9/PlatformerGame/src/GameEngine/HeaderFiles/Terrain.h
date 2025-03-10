#pragma once
#include "HeaderFiles/Vendor/glm/gtc/matrix_transform.hpp"
#include <Model.h>
#include <Texture.h>

class Terrain
{
public:


private:
	const static float SIZE;//this is the size of each terrain tile
	float VERTEX_COUNT;//this is the amount of verts that each terrain tile has
    std::string heightMap;
	float** heights;
	int width;
	int height;
	int BPP;

	float   gridX,gridZ;


    Model model;
	Texture texture;

public:
	Terrain(std::string heightMap,float gridX, float gridZ, Texture texture);
	Model getModel();
	Texture getTexture();
	float getGridx();
	float getGridZ();
	float getHeight(float i,float j);

private:
	float barryCentric(glm::vec3 p1, glm::vec3 p2, glm::vec3  p3, glm::vec2  pos);
	Model GenTerrain();
	void GenIndeces(std::vector<glm::uvec3>& inds);
	void loadData(unsigned char* imagebuffer, std::vector<glm::vec3>& vertList, std::vector<glm::vec3>& normalsList, std::vector<glm::vec2>& uvsList);
	glm::vec3 getNormal(int x, int z, unsigned char* map);
	float getHeight(int x,int z,unsigned char* map);
};

