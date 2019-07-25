#pragma once;
#include "glm/gtc/matrix_transform.hpp"

class Camera {





public:
	




private:
	glm::vec2 position;
	float width, hieght;
    glm::mat4 projection;



public:
	void setPosition(glm::vec2 position);
	glm::vec2 getPosition();
	void setSize(float width,float hieght);
	float getWidth();
	float getHeight();
	Camera(float width,float hieght); 



private:









};
