#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

uniform sampler2D lightTexture;
uniform sampler2D cubeTexture;

void main()
{ 
  FragColor = mix(texture(lightTexture, TexCoords),texture(cubeTexture, TexCoords),0.3f);
}