#version 430 core
in vec3 fPos;
in vec3 fNorm;
in vec2 fTex;

uniform sampler2D diffuse_texture;
uniform sampler2D normal_texture;
uniform sampler2D roughness_texture;

out vec4 FragColor;

struct PointLight{
    vec3 local_frame_position;
    float attenuation;
    float strength;
    float radius;
};

uniform PointLight lights[10];
uniform int num_lights;


void main()
{
    FragColor = texture(diffuse_texture, fTex);
}
