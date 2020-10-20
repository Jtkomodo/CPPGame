#include "HeaderFIles/Entity.h"
#include "HeaderFIles/Model.h"
#include <iostream>
#include <MatrixMath.h>


     Entity::Entity(Model &model, glm::vec3 position, glm::vec3 rotation, float scale,float damping,float reflectivity) 
		 :m(model),position(position),rotation(rotation),
	     scale(scale),damping(damping),reflictivity(reflectivity)
	 
	 {

	
}

	void Entity::Draw() {
		
		m.Draw();
	
	}


	void Entity::setModel(Model model) {

		this->m = model;

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
		this->position = position;
		this->trs = getmatrix(position, rotation, scale);
	
	}
	
	
	void Entity::setRotation(glm::vec3 Rotation) {
		this->rotation =Rotation;
		this->trs = getmatrix(position, rotation, scale);
	}


	void Entity::setscale(float scale) {
		this->scale = scale;
		this->trs = getmatrix(position, rotation, scale);
	}




	Model Entity::getModel() {

		return this->m;

	}


	glm::vec3 Entity::getPosition() {
		return this->position;
	}


	glm::vec3 Entity::getRotation() {
		return this->rotation;
	}


	float Entity::getscale() {
		return this->scale;
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

		return this->trs;


	}