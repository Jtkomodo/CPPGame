#version 400 core

uniform sampler2D sampler;
uniform vec3 lightColor;//our lightColor
uniform bool haslight;

in vec2 tex;//this is the uv coords
in vec3 toLight;//this is the vector from the vertex to the light
in vec3 surfaceNoraml;//this is the surface normal after translation

out vec4 out_color;
void main(){    

//preparing for dot product
vec3 unitNormal=normalize(surfaceNoraml);
vec3 unitToLight=normalize(toLight);

float dotn=dot(unitNormal,unitToLight);


float Brightness=max(dotn,0);
if(!haslight){
Brightness=1;
}



vec3 diffuse=Brightness*lightColor;

out_color=vec4(diffuse,1)*texture2D(sampler,tex);



}