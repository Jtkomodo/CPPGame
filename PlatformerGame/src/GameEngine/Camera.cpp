#include "Camera.h"



Camera::Camera(float width,float height) {
	Camera::width = width;
	Camera::height = height;
	Camera::position = glm::vec2(0, 0);

	Camera::projection=glm::ortho(-width/2, width/2, -height/2, height/2, 0.0f, 1.0f);

}

void Camera::setSize(float width, float height)
{
	Camera::width = width;
	Camera::height = height;
	Camera::projection = glm::ortho(-width / 2, width / 2, -height / 2, height / 2, 0.0f, 1.0f);


}

void Camera::setPosition(glm::vec2 position)
{
	Camera::position = position;
}

float Camera::getWidth()
{
	return width;
}

float Camera::getHeight()
{
	return height;
}

glm::vec2 Camera::getPosition()
{
	return position;
}

glm::mat4 Camera::getProjection()
{
	const glm::mat4 id(1);
	
	glm::mat4 pos = glm::translate(id,glm::vec3(position,0));
	glm::mat4 target=projection* pos;
	
	return target;




}
