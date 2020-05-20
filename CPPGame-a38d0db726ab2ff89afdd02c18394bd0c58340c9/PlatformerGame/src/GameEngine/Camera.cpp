#include "HeaderFIles/Camera.h"
#include "MatrixMath.h";



Camera::Camera(float width,float height,float fov,glm::vec3 rotation) {
	Camera::width = width;
	Camera::height = height;
	Camera::position = glm::vec3(0);
	Camera::fov = fov;
	Camera::rotation = rotation;

	Camera::projection = glm::perspective(glm::radians(fov),width/height,0.1f,1000.0f);

}

void Camera::setSize(float width, float height)
{
	Camera::width = width;
	Camera::height = height;
	Camera::projection = glm::perspective(glm::radians(fov), width / height, 0.1f, 1000.0f);


}

void Camera::setPosition(glm::vec3 position)
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

glm::vec3 Camera::getPosition()
{
	return position;
}

glm::mat4 Camera::getProjection()
{
	
	
	return projection;




}

glm::mat4 Camera::getView() {

	glm::mat4 id=getViewMatrix(position, rotation);
	return id;
}




float Camera::getFOV() {
	return Camera::fov;
}

void Camera::setFOV(float fov) {
	Camera::fov=fov;
	Camera::projection = glm::perspective(glm::radians(fov), width / height, 0.1f, 1000.0f);



}

void Camera::setRotation(glm::vec3 rotation)
{
	Camera::rotation = rotation;

}
