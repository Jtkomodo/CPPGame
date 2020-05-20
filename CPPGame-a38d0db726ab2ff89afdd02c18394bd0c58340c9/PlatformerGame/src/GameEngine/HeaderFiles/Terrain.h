#pragma once
#include "HeaderFiles/Vendor/glm/gtc/matrix_transform.hpp"
#include <Model.h>
#include <Texture.h>

class Terrain
{
public:


private:
    const static float SIZE;//this is the size of each terrain tile
	const static int VERTEX_COUNT = 128;//this is the amount of verts that each terrain tile has
	glm::vec3 postion;
	Model *model;
	Texture *texture;

public:
	Terrain(glm::vec3 position,Texture texture);

private:



};

