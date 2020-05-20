#version 400 core


in vec2  textureCoords;
in vec3 vertices;
in vec3 normals;

uniform vec3 LightPosition;
uniform mat4 projection;
uniform mat4 rts;
uniform float damp;
uniform float refect;



out vec2 tex;//allows this variable to be sent to the fragment shader
out vec3 toLight;
out vec3 surfaceNoraml;
out vec3 toCamera;
void main(){
tex=textureCoords;
vec3 worldPosition=(rts*vec4(vertices,1.0)).xyz;//this is the actaul world position after placed in world
vec4 finalPosition=projection*vec4(worldPosition,1.0);//this is the position as shown on the screen after the projectionmatrix is used
gl_Position=finalPosition;


surfaceNoraml=(rts*vec4(normals,0.0)).xyz;
toLight=LightPosition-worldPosition;


} 

