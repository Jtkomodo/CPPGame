#pragma once
#include "HeaderFiles/Vendor/glm/gtc/matrix_transform.hpp"
#include <Model.h>
#include <Texture.h>

class Terrain
{
public:


private:
	const static float SIZE;//this is the size of each terrain tile
	const static float VERTEX_COUNT;//this is the amount of verts that each terrain tile has
	float   gridX,gridZ;


    Model model;
	Texture texture;

public:
	Terrain(float gridX, float gridZ, Texture texture);
	Model getModel();
	Texture getTexture();
	float getGridx();
	float getGridZ();

private:
	Model GenTerrain();
	void GenIndeces(std::vector<glm::uvec3>& inds);
	void loadData(std::vector<glm::vec3> &vertList,std::vector<glm::vec3> &normalsList,std::vector<glm::vec2> &uvsList);

};

