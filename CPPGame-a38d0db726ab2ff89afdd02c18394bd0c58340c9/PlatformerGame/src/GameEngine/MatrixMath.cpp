#include "HeaderFiles/Vendor/glm/gtc/matrix_transform.hpp"
#include "MatrixMath.h"


glm::mat4 getmatrix(glm::vec3 position, glm::vec3 angle, float scale) {


	glm::mat4 i = glm::mat4(1);
	i = glm::translate(i,position);



	i = glm::rotate(i, glm::radians(angle.x), glm::vec3(1, 0, 0));
	i = glm::rotate(i, glm::radians(angle.y), glm::vec3(0, 1, 0));
	i = glm::rotate(i, glm::radians(angle.z), glm::vec3(0, 0, 1));




	i = glm::scale(i, glm::vec3(scale));

	
	

	return i;

}



glm::mat4 getViewMatrix(glm::vec3 position, glm::vec3 angle) {


	glm::mat4 i = glm::mat4(1);
	



	i = glm::rotate(i, glm::radians(-angle.x), glm::vec3(1, 0, 0));
	i = glm::rotate(i, glm::radians(-angle.y), glm::vec3(0, 1, 0));
	i = glm::rotate(i, glm::radians(-angle.z), glm::vec3(0, 0, 1));

	i = glm::translate(i, -position);


	return i;

}