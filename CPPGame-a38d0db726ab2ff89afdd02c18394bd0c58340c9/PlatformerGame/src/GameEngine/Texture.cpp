#define STB_IMAGE_IMPLEMENTATION

#include "HeaderFiles/Texture.h"
#include <string>
#include <GL\glew.h>
#include "HeaderFiles/Vendor/stb_image.h"



Texture::Texture(std::string name) {
	Texture::path = name;
	
	cpuBuffer = stbi_load(path.c_str(),&width,&height,&BPP,4);//loads in the texture data into cpuBuffer and stores the width,height and bpp

	
	glGenTextures(1,&Id);//this allocates a buffer and sets a id to use it
	glBindTexture(GL_TEXTURE_2D,Id);//binds the buffer to texture2d
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);//tells how the data is formated 
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);//sets the filters to gl_nearest so that the pixel art will look right
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,cpuBuffer);//loads in the texture to the GPU for use later
	glBindTexture(GL_TEXTURE_2D, 0);//unbinds
}

Texture::~Texture()
{
	glDeleteTextures(1, &Id);
	stbi_image_free(cpuBuffer);

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