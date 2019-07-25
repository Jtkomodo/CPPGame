#pragma once
class TIleData
{
	/*
	This is just a class that holds all the data I need for the uv coords of   
	the Tiles.It simulates javas enums.
    */
public:
	//defines my "enums" 
	static  TIleData Dirt;
	static  TIleData Grass;
	static  TIleData Grassw;
	static  TIleData Water;

private:

	float value[8];

	
private:
	TIleData(float value[8]) {
		
		for (int i = 0; i < 8; i++) {
			this->value[i] = value[i];
		}
	}
		

public:

	float* getValue() {

		return this->value;
	}














};

