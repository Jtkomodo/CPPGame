#include "HeaderFiles/Model.h"
#include <GL\glew.h>
#include <iostream>



Model::Model(std::vector<glm::vec3> verts, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals, std::vector<glm::uvec3> inds) {

	//defing buffers to load values in
	glGenVertexArrays(1, &VAO_ID);
	glBindVertexArray(VAO_ID);

	Model::drawCount =inds.size()*3;
	//std::cout <<ind[6]<< std::endl;
	glGenBuffers(1, &VertI);
	glGenBuffers(1, &UVI);
	glGenBuffers(1, &INDI);
	glGenBuffers(1, &NORMALSI);

	enableAtrib();

	//loading values into buffers 
	glBindBuffer(GL_ARRAY_BUFFER, VertI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &verts[0], GL_STATIC_DRAW);//loading data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib


// loading values into buffers
	glBindBuffer(GL_ARRAY_BUFFER, UVI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);//loading data
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib


	glBindBuffer(GL_ARRAY_BUFFER, NORMALSI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);//loading data
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib





	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, inds.size()* sizeof(glm::uvec3),&inds[0], GL_STATIC_DRAW);//loading data
	glBindVertexArray(0);
}

void Model::Draw()
{
	glBindVertexArray(VAO_ID);
	glDrawElements(GL_TRIANGLES,Model::drawCount,GL_UNSIGNED_INT,0);





}

void Model::enableAtrib() {
	glEnableVertexAttribArray(0);//enabling vertex attrib
    glEnableVertexAttribArray(1);//enabling vertex attrib
	glEnableVertexAttribArray(2);//enabling vertex attrib

}






Model::~Model() {
	glDeleteVertexArrays(1, &VAO_ID);
	
}
