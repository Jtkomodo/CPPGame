#include "HeaderFiles/Model.h"
#include <GL\glew.h>
#include <iostream>




Model::Model(float Verts[],float uv[],float ind[]) {
	//Model::Verts[0] = Verts[0];
	//defing buffers to load values in
	drawCount = sizeof(ind);
	glGenBuffers(1, &VertI);
	glGenBuffers(1, &UVI);
	glGenBuffers(1, &INDI);


   //loading values into buffers 
	glBindBuffer(GL_ARRAY_BUFFER, VertI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Verts) * sizeof(float), Verts, GL_STATIC_DRAW);//loading data
	
	glEnableVertexAttribArray(0);//enabling vertex attrib
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//defing the vertex atrib
	
																		  
// loading values into buffers
		glBindBuffer(GL_ARRAY_BUFFER, UVI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(uv) * sizeof(float), uv, GL_STATIC_DRAW);//loading data

	glEnableVertexAttribArray(1);//enabling vertex attrib
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//defing the vertex atrib

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ind) * sizeof(int), ind, GL_STATIC_DRAW);//loading data

	


	//glBindBuffer(GL_ARRAY_BUFFER,0);

}
void Model::Draw()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glDrawElements(GL_TRIANGLES,drawCount,GL_UNSIGNED_INT,0);





}


Model::~Model() {
	
	glDeleteBuffers(1,&VertI);
	glDeleteBuffers(1, &UVI);
	glDeleteBuffers(1, &INDI);
}
