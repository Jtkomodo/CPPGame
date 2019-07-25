#include "TIleData.h"



float dirtuv[8] = {

	   0,0,//top left
	0.25f,0,//top right
	0.25f,0.25f,//bottom right
	0,0.25f//bo

};

float grassuv[8] = {

	0.25f,0,
	0.5f,0,
	0.5f,0.25f,
	0.25f,0.25f

};
float grasswuv[8] = {

  0.5f,0,
	0.75f,0,
	0.75f,0.25f,
	0.5f,0.25f

};
float wateruv[8] = {

	0.75f,0.25f,
	1,0.25f,
	1,0.5f,
	0.75f,0.5f


};

TIleData TIleData::Dirt = TIleData(dirtuv);
TIleData TIleData::Grass = TIleData(grassuv);
TIleData TIleData::Grassw = TIleData(grasswuv);
TIleData TIleData::Water = TIleData(wateruv);
