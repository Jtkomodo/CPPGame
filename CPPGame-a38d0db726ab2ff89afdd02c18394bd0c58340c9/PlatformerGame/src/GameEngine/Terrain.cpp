#include "Terrain.h"
#include <Vendor\stb_image.h>





const float max_height = 100;
const float Terrain::SIZE = 800;



Terrain::Terrain(std::string heightMap,float gridX,float gridY,Texture texture) :heightMap(heightMap),gridX(gridX*SIZE), gridZ(gridZ*SIZE), texture(texture), model(GenTerrain()) {

    


}




Model Terrain::GenTerrain() {
    std::string FILE = "src/res/heightMaps/";
    std::string ending = ".png";

    std::string fullpath = FILE + heightMap + ending;



    unsigned char* imagebuffer = stbi_load(fullpath.c_str(), &width, &height, &BPP, STBI_grey);//loads in the texture data into cpuBuffer and stores the width,height and bpp
    if (imagebuffer == NULL) {
        std::cout << "the terrain heightmap file " + fullpath + " could not be found!!!" << std::endl;
    }
    VERTEX_COUNT = width;
    int count = Terrain::VERTEX_COUNT * Terrain::VERTEX_COUNT;

    std::vector<glm::vec3> verts(count);
    std::vector<glm::vec2> uvs(count);
    std::vector<glm::vec3> normals(count);
    loadData(imagebuffer,verts, normals, uvs);
    std::vector<glm::uvec3> inds(2*(VERTEX_COUNT-1)*(VERTEX_COUNT-1));
    
  
    GenIndeces(inds);

    return Model(verts,uvs,normals,inds);




    
}


void Terrain::GenIndeces(std::vector<glm::uvec3> &inds) {

    int location = 0;
    for (int gz = 0; gz < (VERTEX_COUNT - 1); gz++) {
        for (int gx = 0; gx < (VERTEX_COUNT - 1); gx++) {
            int topLeft = (gz * VERTEX_COUNT) + gx;
            int topRight = topLeft + 1;
            int bottomLeft = ((gz + 1) * VERTEX_COUNT) + gx;
            int bottomRight = bottomLeft + 1;
            
            //first triamgle
            int trivert1 = topLeft;
            int trivert2 = bottomLeft;
            int trivert3 = topRight;

            //second triangle
            int tri2vert1 = topRight;
            int tri2vert2=bottomLeft;
            int tri2vert3= bottomRight;

            inds[location++] = glm::uvec3(trivert1, trivert2, trivert3);
            inds[location++] = glm::uvec3(tri2vert1, tri2vert2, tri2vert3);


        }
    }



}





void Terrain::loadData(unsigned char* imagebuffer,std::vector<glm::vec3> &vertList, std::vector<glm::vec3> &normalsList, std::vector<glm::vec2> &uvsList)
{
    //loads in the data we need;

    


    int currentLocation = 0;
    for (int i = 0; i < VERTEX_COUNT; i++) {
        for (int j = 0; j < VERTEX_COUNT; j++) {

            float x = (float)j / ((float)VERTEX_COUNT - 1) * SIZE;
            float z = (float)i / ((float)VERTEX_COUNT - 1) * SIZE;
            float y = getHeight(j, i, imagebuffer)-max_height/2;
            vertList[currentLocation] = glm::vec3(x, y, z);
            normalsList[currentLocation] = glm::vec3(0, 1, 0);
            float ux = (float)j / ((float)VERTEX_COUNT - 1);
            float uy = (float)i / ((float)VERTEX_COUNT - 1);
            uvsList[currentLocation] = glm::vec2(ux, uy);
            currentLocation++;
        }

      //  stbi_image_free(imagebuffer);
    }
}

float Terrain::getHeight(int x, int z, unsigned char* map)
{
    float y=0;
    if (x >= 0 && x<=width&& z>=0 && z<=height) {
        y+=((float)map[(z*width)+ x]/256)*(max_height);
     
    }



    return y;
}
Model Terrain::getModel()
{
    return this->model;
}

Texture Terrain::getTexture() {
    return this->texture;
}

float Terrain::getGridx() {
    return this->gridX;
}
float Terrain::getGridZ() {
    return this->gridZ;
}








