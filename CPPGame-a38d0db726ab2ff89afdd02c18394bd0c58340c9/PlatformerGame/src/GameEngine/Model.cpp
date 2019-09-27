#include "HeaderFiles/Model.h"
#include <GL\glew.h>
#include <iostream>

Model::Model() {


}


Model::Model(float Verts[],float uv[],int ind[],int size1,int size2,int size3) {
	Model::Verts = Verts;
	//defing buffers to load values in



	Model::drawCount = size3;
	//std::cout <<ind[6]<< std::endl;
	glGenBuffers(1, &VertI);
	glGenBuffers(1, &UVI);
	glGenBuffers(1, &INDI);


	

	//loading values into buffers 
	glBindBuffer(GL_ARRAY_BUFFER, VertI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, size1 * sizeof(float), Verts, GL_STATIC_DRAW);//loading data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib


// loading values into buffers
	glBindBuffer(GL_ARRAY_BUFFER, UVI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, size2 * sizeof(float), uv, GL_STATIC_DRAW);//loading data
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size3 * sizeof(int), ind, GL_STATIC_DRAW);//loading data

}

void Model::Draw()
{

	glBindBuffer(GL_ARRAY_BUFFER,VertI);
	glEnableVertexAttribArray(0);//enabling vertex attrib



	glEnableVertexAttribArray(1);//enabling vertex attrib


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glDrawElements(GL_TRIANGLES,Model::drawCount,GL_UNSIGNED_INT,0);





}

float* Model::getvert()
{
	return Model::Verts;

}


Model::~Model() {
	
	glDeleteBuffers(1,&VertI);
	glDeleteBuffers(1, &UVI);
	glDeleteBuffers(1, &INDI);
}
