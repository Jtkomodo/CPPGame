#include "BatchedModel.h"
#include <GL\glew.h>
#include <cstddef>




BatchedModel::BatchedModel() {
	
	
	drawCount = 0;
	glGenBuffers(1,&VertI);
	glGenBuffers(1, &UVI);
	glGenBuffers(1, &INDI);


	glBindBuffer(GL_ARRAY_BUFFER, VertI);
	glBindBuffer(GL_ARRAY_BUFFER, VertI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, 1000 * sizeof(float),NULL, GL_DYNAMIC_DRAW);//loading data
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib


// loading values into buffers
	glBindBuffer(GL_ARRAY_BUFFER, UVI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, 1000 * sizeof(float), NULL, GL_DYNAMIC_DRAW);//loading data
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 1000 * sizeof(int),NULL, GL_DYNAMIC_DRAW);//loading data





}
void BatchedModel::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, VertI);
	glEnableVertexAttribArray(0);//enabling vertex attrib


	glBindBuffer(GL_ARRAY_BUFFER, UVI);
	glEnableVertexAttribArray(1);//enabling vertex attrib




	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);

}

void BatchedModel::addValuesToVBO(float verts[8],float uv[8]) {

	glBindBuffer(GL_ARRAY_BUFFER, VertI);//binding buffer
	
	glBufferSubData(GL_ARRAY_BUFFER,pionter,8*sizeof(float),verts);

	glBindBuffer(GL_ARRAY_BUFFER, UVI);//binding buffer

	glBufferSubData(GL_ARRAY_BUFFER, pionter, 8 * sizeof(float), uv);

	int indices[] = {

		indbase,indbase+1,indbase+2,
	     indbase+2,indbase+3,indbase

	};



	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,INDI);
	glBufferSubData(GL_ARRAY_BUFFER, drawCount2, 6 * sizeof(int), uv);

	drawCount = drawCount + 6;//used for telling the amount of triangles to draw when the drawcall is made
	drawCount2 = drawCount * 4;
	indbase = indbase + 4;//this makes sure that the indeces are loaded in right other wise it will  draw the same model multiple times
	pionter = pionter + (8 * 4);//pionter to the next value in the vertex and uv buffers so that it won't write over the old ones
	sections++;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER,0);

}

void BatchedModel::flushBuffers()
{

	glBufferData(GL_ARRAY_BUFFER, 1000 * sizeof(float), NULL, GL_DYNAMIC_DRAW);//loading data
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib


// loading values into buffers
	glBindBuffer(GL_ARRAY_BUFFER, UVI);//binding buffer
	glBufferData(GL_ARRAY_BUFFER, 1000 * sizeof(float), NULL, GL_DYNAMIC_DRAW);//loading data
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);//defing the vertex atrib

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDI);//binding buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 1000 * sizeof(int), NULL, GL_DYNAMIC_DRAW);//loading data



	drawCount = 0;
	drawCount2 = 0;
	indbase = 0;
	pionter = 0;
	sections = 0;

}
