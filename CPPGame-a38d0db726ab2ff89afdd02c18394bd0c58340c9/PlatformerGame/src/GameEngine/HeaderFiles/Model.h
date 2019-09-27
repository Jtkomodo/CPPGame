#pragma once
class Model
{
	//vars

public:

private:
	unsigned int VertI,UVI,INDI,drawCount;
	float* Verts;

//functions

	public:
	//	Model(float verts[],float uv[],float ind[]);
		
		Model(float Verts[], float uv[], int ind[], int size1, int size2, int size3);
		
		void Draw();
		float * getvert();

		Model();
	     ~Model();
private:
	  
	







};

