#version 430 core
in vec3 fPos;
in vec3 fNorm;
in vec2 fTex;

uniform sampler2D diffuse_texture;
uniform sampler2D normal_texture;
uniform sampler2D roughness_texture;

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0,0.9,0.6, 1.0);
}
