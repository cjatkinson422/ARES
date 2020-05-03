#version 430 core
in vec3 fPos;
in mat3 fNTB;
in vec2 fTex;

uniform sampler2D texture0; // Diffuse
uniform sampler2D texture1; // Normal
uniform sampler2D texture2; // Specular
uniform sampler2D texture3; 

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0,0.9,0.6, 1.0);
}
