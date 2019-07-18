#include "HeaderFiles/Model.h"
#include <GL\glew.h>
#include <iostream>




Model::Model(float Verts[]) {
	//Model::Verts[0] = Verts[0];
	//defing buffers to load values in
	glGenBuffers(1, &Vert);

   //loading values into buffers 
	glBindBuffer(GL_ARRAY_BUFFER, Vert);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Verts) * sizeof(float), Verts, GL_STATIC_DRAW);//loading data
	
	glEnableVertexAttribArray(0);//enabling vertex attrib
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//defing the vertex atrib

	//glBindBuffer(GL_ARRAY_BUFFER,0);

}
/*void Model::Draw() {


}*/
Model::~Model() {
	
	glDeleteBuffers(1,&Vert);
}
void Model::printTest() {
	
	//std::cout << "model:"<<Verts[0]<<"!" << std::endl;
}