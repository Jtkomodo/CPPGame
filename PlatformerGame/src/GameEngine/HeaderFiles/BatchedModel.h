#pragma once
class BatchedModel
{


	//vars

public:

private:
	unsigned int VertI, UVI, INDI;
	int drawCount, pionter = 0, indbase,drawCount2,sections=0;
	//float Verts[];

//functions

public:
	BatchedModel();
	void Draw();
	
	void addValuesToVBO(float verts[8],float uv[8]);
	void flushBuffers();

private:












};

