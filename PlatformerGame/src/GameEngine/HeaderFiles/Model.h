#pragma once
class Model
{
	//vars

public:

private:
	unsigned int VertI,UVI,INDI,drawCount;
	//float Verts[];
	unsigned int Vert;
	float Verts[];

//functions

	public:
		Model(float verts[8],float uv[8],int ind[6]);
		void Draw();
		Model(float verts[]);
		//void Draw();

	     ~Model();
		void printTest();









};

