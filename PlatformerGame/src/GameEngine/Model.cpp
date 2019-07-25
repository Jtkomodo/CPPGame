#include "HeaderFiles/Model.h"
#include <GL\glew.h>
#include <iostream>




<<<<<<< HEAD
Model::Model(float Verts[8],float uv[8],int ind[6]) {
	//Model::Verts[0] = Verts[0];
	//defing buffers to load values in
	


	drawCount =6;
	//std::cout <<ind[6]<< std::endl;
	glGenBuffers(1, &VertI);
	glGenBuffers(1, &UVI);
	glGenBuffers(1, &INDI);


   //loading values into buffers 
	glBindBuffer(GL_ARRAY_BUFFER, VertI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), Verts, GL_STATIC_DRAW);//loading data
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib

																		  
// loading values into buffers
		glBindBuffer(GL_ARRAY_BUFFER, UVI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, 8* sizeof(float), uv, GL_STATIC_DRAW);//loading data
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(int), ind, GL_STATIC_DRAW);//loading data

	

=======
Model::Model(float Verts[]) {
	//Model::Verts[0] = Verts[0];
	//defing buffers to load values in
	glGenBuffers(1, &Vert);

   //loading values into buffers 
	glBindBuffer(GL_ARRAY_BUFFER, Vert);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Verts) * sizeof(float), Verts, GL_STATIC_DRAW);//loading data
	
	glEnableVertexAttribArray(0);//enabling vertex attrib
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//defing the vertex atrib
>>>>>>> parent of a38d0db... added a whole lot

	glBindBuffer(GL_ARRAY_BUFFER,0);

}
<<<<<<< HEAD
void Model::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, VertI);
	glEnableVertexAttribArray(0);//enabling vertex attrib
	
	
	glBindBuffer(GL_ARRAY_BUFFER, UVI);
	glEnableVertexAttribArray(1);//enabling vertex attrib
	



	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	  glDrawElements(GL_TRIANGLES,drawCount,GL_UNSIGNED_INT,0);





}
=======
/*void Model::Draw() {
>>>>>>> parent of a38d0db... added a whole lot


}*/
Model::~Model() {
	
	glDeleteBuffers(1,&Vert);
}
void Model::printTest() {
	
	//std::cout << "model:"<<Verts[0]<<"!" << std::endl;
}