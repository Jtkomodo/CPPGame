#pragma once
#include "glm/gtc/matrix_transform.hpp"


class Camera {

public:


private:
	glm::vec2 position;
	float width, height;
	glm::mat4 projection;


public:
	Camera(float width,float height);
	void setSize(float width,float height);
	void setPosition(glm::vec2 position);
	float getWidth();
	float getHeight();
	glm::vec2 getPosition();
	glm::mat4 getProjection();



	


private:










};