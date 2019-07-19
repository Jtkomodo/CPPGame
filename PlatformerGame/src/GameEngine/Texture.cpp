#define STB_IMAGE_IMPLEMENTATION

#include "HeaderFiles/Texture.h"
#include <string>
#include <GL\glew.h>
#include "HeaderFiles/Vendor/stb_image.h"



Texture::Texture(std::string name) {
	Texture::path = name;
	
	cpuBuffer = stbi_load(path.c_str(),&width,&height,&BPP,4);

	
	glGenTextures(1,&Id);
	glBindTexture(GL_TEXTURE_2D,Id);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,cpuBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

}

Texture::~Texture()
{
	glDeleteTextures(1, &Id);
	stbi_image_free(cpuBuffer);

}

void Texture::Bind(unsigned int sampler) {
	if (sampler <= 31) {
		glActiveTexture(GL_TEXTURE0+sampler);
		glBindTexture(GL_TEXTURE_2D, &Id);


	}
}
void Texture::unBind() {

	glBindTexture(GL_TEXTURE_2D, 0);


}