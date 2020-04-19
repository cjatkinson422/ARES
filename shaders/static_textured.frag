#version 430 core
in vec3 fPos;
in vec3 fNorm;
in vec2 fTex;

uniform sampler2D texture0; // Diffuse
uniform sampler2D texture1; // Normal
uniform sampler2D texture2; // Specular
uniform sampler2D texture3; 

out vec4 FragColor;

struct PointLight{
    vec3 position;
    float surface_intensity;
    float radius;
    float attenuation_coefficient;
};

uniform PointLight light;
uniform int num_lights;


void main()
{
    vec3 norm = normalize(fNorm);
    vec3 lightDir = normalize(light.position - fPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diff * texture(texture0, fTex);

    vec3 viewDir = normalize(-fPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 1.0);
    vec4 specular = spec * texture(texture1, fTex);
    
    FragColor = diffuse;
}
