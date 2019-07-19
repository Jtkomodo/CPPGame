#pragma once
class Model
{
	//vars

public:

private:
	unsigned int VertI,UVI,INDI,drawCount;
	float Verts[];

//functions

	public:
		Model(float verts[],float uv[],float ind[]);
		void Draw();
	     ~Model();
private:
	  
	







};

