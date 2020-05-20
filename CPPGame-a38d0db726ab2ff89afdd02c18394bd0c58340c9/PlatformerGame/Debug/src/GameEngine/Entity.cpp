#include "HeaderFIles/Entity.h"
#include "HeaderFIles/Model.h"
#include <iostream>
#include <MatrixMath.h>


	Entity::Entity(Model* model, glm::vec3 position, glm::vec3 rotation, float scale,float damping,float reflectivity) {

		Entity::m =model;
		Entity::position = position;
		Entity::rotation = rotation;
		Entity::scale = scale;
		Entity::trs = getmatrix(position,rotation,scale);
		Entity::damping = damping;
		Entity::reflictivity = reflectivity;

}

	void Entity::Draw() {
		
		(*m).Draw();
	
	}


	void Entity::setModel(Model* model) {

		Entity::m = model;

	}

	void Entity::setDamping(float damping)
	{
		this->damping = damping;
	}

	void Entity::setReflect(float reflect)
	{
		this->reflictivity = reflect;
	}


	void Entity::setPosition(glm::vec3 position) {
		Entity::position = position;
		Entity::trs = getmatrix(position, rotation, scale);
	
	}
	
	
	void Entity::setRotation(glm::vec3 Rotation) {
		Entity::rotation =Rotation;
		Entity::trs = getmatrix(position, rotation, scale);
	}


	void Entity::setscale(float scale) {
		Entity::scale = scale;
		Entity::trs = getmatrix(position, rotation, scale);
	}




	Model* Entity::getModel() {

		return m;

	}


	glm::vec3 Entity::getPosition() {
		return Entity::position;
	}


	glm::vec3 Entity::getRotation() {
		return Entity::rotation;
	}


	float Entity::getscale() {
		return Entity::scale;
	}


	float Entity::getDamping()
	{
		return this->damping;
	}

	float Entity::getReflect()
	{
		return this->reflictivity;
	}

	glm::mat4 Entity::getTRS() {

		return Entity::trs;


	}