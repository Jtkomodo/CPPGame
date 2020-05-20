#pragma once
#include "HeaderFiles/Vendor/glm/gtc/matrix_transform.hpp"
#include "HeaderFiles/Model.h"

class Entity {


//vars
public:
	
	
private:



	Model *m=0;
	float reflictivity;
	float damping;
	glm::vec3 position;
	glm::vec3 rotation;
	float scale;
	glm::mat4 trs;
	


//methods


public:
	Entity(Model *model,glm::vec3 position,glm::vec3 rotation,float scale,float damping,float reflectivity );
	void Draw();
	void setPosition(glm::vec3 position);
	void setRotation(glm::vec3 Rotation);
	void setscale(float scale);
	void setModel(Model *model);
	void setDamping(float damping);
	void setReflect(float reflect);



	float getDamping();
	float getReflect();

	glm::mat4 getTRS();
    glm::vec3 getPosition();
	glm::vec3 getRotation();
	float getscale();
	Model* getModel();





private:







};