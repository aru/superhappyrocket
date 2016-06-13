// The TexturedIdentity Shader
// Fragment Shader
// Richard S. Wright Jr.
// OpenGL SuperBible
#version 330


uniform sampler2D colorMap;

out vec4 vFragColor;
smooth in vec2 vVaryingTexCoords;


void main(void)
   { 
   vFragColor = texture(colorMap, vVaryingTexCoords.st);
   }