#pragma once

#include <string>


class Texture {

//vars
public:


private:
	unsigned int Id;
	std::string path;
	 unsigned char *cpuBuffer;
	int width, height,BPP;



//functions

public:
	Texture(std::string name);
	~Texture();
	void Bind(unsigned int sampler );
	void unBind();
private:




};