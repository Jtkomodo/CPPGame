#version 120


attribute vec2  textureCoords;

attribute vec3 vertices;

uniform mat4 projection;
uniform mat4 rts;
mat4 matrix;

varying vec2 tex;//allows this variable to be sent to the fragment shader

void main(){
tex=textureCoords;

  gl_Position=projection*rts*vec4(vertices,1.0);

} 

