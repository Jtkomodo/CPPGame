#pragma once
class Model
{
	//vars

public:

private:
	unsigned int VertI,UVI,INDI,NORMALSI,drawCount,VAO_ID;
	float* Verts;

//functions

	public:
	//	Model(float verts[],float uv[],float ind[]);
		
		Model(float Verts[], float uv[],float normals[], int ind[], int size1, int size2, int size3,int size4);
		
		void Draw();
		float * getvert();

		Model();
	     ~Model();
private:
	  
	void enableAtrib();







};

