#include "Light.h"

Light::Light(glm::uvec3 position, glm::vec3 color)
{
	Light::position = position;
	Light::color = color;

}

void Light::setPosition(glm::vec3 position)
{
	Light::position = position;
}

void Light::setColor(glm::vec3 color)
{
	Light::color = color;
}

glm::vec3 Light::getPosition()
{
	return Light::position;
}

glm::vec3 Light::getColor()
{
	return Light::color;
}
