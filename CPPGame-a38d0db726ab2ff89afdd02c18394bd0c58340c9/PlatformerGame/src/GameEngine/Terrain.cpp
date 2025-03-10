#include "Terrain.h"
#include <Vendor\stb_image.h>





const float max_height = 100;
const float Terrain::SIZE = 800;



Terrain::Terrain(std::string heightMap,float gridX,float gridY,Texture texture) :heightMap(heightMap),gridX(gridX*SIZE), gridZ(gridZ*SIZE), texture(texture), model(GenTerrain()) {

    


}




float Terrain::barryCentric(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec2 pos)
{
    float det = (p2.z - p3.z) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.z - p3.z);
    float l1 = ((p2.z - p3.z) * (pos.x - p3.x) + (p3.x - p2.x) * (pos.y - p3.z)) / det;
    float l2 = ((p3.z - p1.z) * (pos.x - p3.x) + (p1.x - p3.x) * (pos.y - p3.z)) / det;
    float l3 = 1.0f - l1 - l2;
    return l1 * p1.y + l2 * p2.y + l3 * p3.y;
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
    int count = VERTEX_COUNT * VERTEX_COUNT;
    
    this->heights = new float*[VERTEX_COUNT];
    for (int i = 0; i < VERTEX_COUNT;i++) {
        heights[i] = new float[VERTEX_COUNT];
    }

    std::vector<glm::vec3> verts(count);
    std::vector<glm::vec2> uvs(count);
    std::vector<glm::vec3> normals(count);
    loadData(imagebuffer,verts, normals, uvs);
    std::vector<glm::uvec3> inds(2*(VERTEX_COUNT-1)*(VERTEX_COUNT-1));
    
  
    GenIndeces(inds);
    stbi_image_free(imagebuffer);
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
            float y = getHeight(j, i, imagebuffer);
            heights[j][i] = y;

            vertList[currentLocation] = glm::vec3(x, y, z)
          ;  normalsList[currentLocation] = getNormal(j, i, imagebuffer);
            float ux = (float)j / ((float)VERTEX_COUNT - 1);
            float uy = (float)i / ((float)VERTEX_COUNT - 1);
            uvsList[currentLocation] = glm::vec2(ux, uy);
            currentLocation++;
        }

      //  stbi_image_free(imagebuffer);
    }
}
glm::vec3 Terrain::getNormal(int x,int z,unsigned char* map) {
    
    float L = getHeight(x - 1, z, map);
    float R = getHeight(x + 1, z, map);
    float D = getHeight(x,z-1, map);
    float U = getHeight(x,z+1, map);
    glm::vec3 normal(L-R,2.0,D-U);
    normal=glm::normalize(normal);
    return normal;
}




float Terrain::getHeight(int x, int z, unsigned char* map)
{
    float y=0;
    if (x >= 0 && x<=width&& z>=0 && z<=height) {
        y+=((float)map[(z*width)+ x]/256)*(max_height);
     
    }



    return y - max_height / 2;
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

float Terrain::getHeight(float x, float z)
{
    float s=SIZE / (VERTEX_COUNT-1);
    int j= floorf(x/s);
    int i= floorf(z/s);
    std::cout <<"("<<x<<","<<z<< ")("<<j<<","<<i<<")" << std::endl;


    if (i>=0 && i<this->VERTEX_COUNT-1 && j >= 0 && j < this->VERTEX_COUNT-1) {

      float xCoord = (std::fmod(x,s)) / s;
      float zCoord = (std::fmod(z,s)) / s;
      float answer;
     if (xCoord <= (1-zCoord)) {
			answer = barryCentric(glm::vec3(0, heights[j][i], 0),glm::vec3(1,
							heights[j + 1][i], 0),glm::vec3(0,
							heights[j][i + 1], 1), glm::vec2(xCoord, zCoord));
		} else {
			answer = barryCentric(glm::vec3(1, heights[j + 1][i], 0),glm::vec3(1,
							heights[j + 1][i + 1], 1),glm::vec3(0,
							heights[j][i + 1], 1),glm::vec2(xCoord, zCoord));
		}
     return answer;
    }
    else {
    
        return 0;
    }
}








