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

private:
	Model GenTerrain();
	void GenIndeces(std::vector<glm::uvec3>& inds);
	void loadData(unsigned char* imagebuffer, std::vector<glm::vec3>& vertList, std::vector<glm::vec3>& normalsList, std::vector<glm::vec2>& uvsList);
	glm::vec3 getNormal(int x, int z, unsigned char* map);
	float getHeight(int x,int z,unsigned char* map);
};

