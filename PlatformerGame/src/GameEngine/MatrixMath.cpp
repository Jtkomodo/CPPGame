#include "glm/gtc/matrix_transform.hpp"
#include "MatrixMath.h"


glm::mat4 getmatrix(glm::vec2 position, float angle, float scale) {


	glm::mat4 i = glm::mat4(1);
	i = glm::rotate(i, glm::radians(angle), glm::vec3(0, 0, 1));
    i = glm::translate(i, glm::vec3(position, 0));
	i = glm::scale(i, glm::vec3(scale));

	

	return i;

}