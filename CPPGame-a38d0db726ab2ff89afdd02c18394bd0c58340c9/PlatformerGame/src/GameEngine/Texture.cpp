#define STB_IMAGE_IMPLEMENTATION

#include "HeaderFiles/Texture.h"
#include <string>
#include <GL\glew.h>
#include "HeaderFiles/Vendor/stb_image.h"
#include <iostream>



Texture::Texture(std::string name) {
	Texture::path = name;

	std::string FILE = "src/res/Textures/";
	std::string ending = ".png";

	std::string fullpath = FILE + path + ending;
	
	cpuBuffer = stbi_load(fullpath.c_str(),&width,&height,&BPP,4);//loads in the texture data into cpuBuffer and stores the width,height and bpp

	if (cpuBuffer ==0) {
		std::cout << "the file " + fullpath + " could not be found!!!" << std::endl;

	}
	glGenTextures(1,&Id);//this allocates a buffer and sets a id to use it
	glBindTexture(GL_TEXTURE_2D,Id);//binds the buffer to texture2d
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);//tells how the data is formated 
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);//sets the filters to gl_nearest so that the pixel art will look right
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,cpuBuffer);//loads in the texture to the GPU for use later
	glBindTexture(GL_TEXTURE_2D, 0);//unbinds

	stbi_image_free(cpuBuffer);
}

Texture::~Texture()
{
	glDeleteTextures(1, &Id);
	

}

void Texture::Bind(unsigned int sampler) {
	if (sampler <= 31) {
		glActiveTexture(GL_TEXTURE0+sampler);
		glBindTexture(GL_TEXTURE_2D, Id);


	}
}
void Texture::unBind() {

	glBindTexture(GL_TEXTURE_2D, 0);


}