#include "Terrain.h"

const float Terrain::SIZE = 800;
const float Terrain::VERTEX_COUNT = 128;

Terrain::Terrain(float gridX,float gridY,Texture texture) :gridX(gridX*SIZE), gridZ(gridZ*SIZE), texture(texture), model(GenTerrain()) {

    


}




Model Terrain::GenTerrain() {
    int count = Terrain::VERTEX_COUNT * Terrain::VERTEX_COUNT;

    std::vector<glm::vec3> verts(count);
    std::vector<glm::vec2> uvs(count);
    std::vector<glm::vec3> normals(count);
    std::vector<glm::uvec3> inds(2*(VERTEX_COUNT-1)*(VERTEX_COUNT-1));
    
    loadData(verts,normals,uvs);
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





void Terrain::loadData(std::vector<glm::vec3> &vertList, std::vector<glm::vec3> &normalsList, std::vector<glm::vec2> &uvsList)
{
    //loads in the data we need;


    int currentLocation = 0;
    for (int i = 0; i < VERTEX_COUNT; i++) {
        for (int j = 0; j < VERTEX_COUNT; j++) {

            float x = (float)j / ((float)VERTEX_COUNT - 1) * SIZE;
            float y = 0;
            float z = (float)i / ((float)VERTEX_COUNT - 1) * SIZE;
            vertList[currentLocation] = glm::vec3(x, y, z);
            normalsList[currentLocation] = glm::vec3(0, 1, 0);
            float ux = (float)j / ((float)VERTEX_COUNT - 1);
            float uy = (float)i / ((float)VERTEX_COUNT - 1);
            uvsList[currentLocation] = glm::vec2(ux, uy);
            currentLocation++;
        }


    }
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








