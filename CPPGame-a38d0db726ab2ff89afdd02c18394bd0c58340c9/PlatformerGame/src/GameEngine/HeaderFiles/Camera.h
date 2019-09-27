#pragma once
#include "glm/gtc/matrix_transform.hpp"


class Camera {

public:


private:
	glm::vec3 position;
	float width, height;
	glm::mat4 projection;
	glm::vec3 rotation;
	float fov;


public:
	Camera(float width,float height,float fov,glm::vec3 rotation);
	void setSize(float width,float height);
	void setPosition(glm::vec3 position);
	float getWidth();
	float getHeight();
	glm::vec3 getPosition();
	glm::mat4 getProjection();

	float getFOV();
	void setFOV(float fov);
	void setRotation(glm::vec3 rotation);


private:










};