#pragma once
#include "Vendor/glm/gtc/matrix_transform.hpp"


class Light {


public:



	
private:
	glm::vec3 position;
	glm::vec3 color;



public:

	Light(glm::uvec3 position,glm::vec3 color);
	void setPosition(glm::vec3 position);
	void setColor(glm::vec3 color);
	glm::vec3 getPosition();
	glm::vec3 getColor();

		

private:







};