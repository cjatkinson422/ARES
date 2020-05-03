#version 430 core
in vec3 fPos;
in mat3 fTBN;
in vec2 fTex;
in vec3 fNorm;

uniform sampler2D texture0; // Diffuse
uniform sampler2D texture1; // Normal
uniform sampler2D texture2; // Specular
uniform sampler2D texture3; 

uniform mat4 model_matrix;

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
    float specularStrength = 2.0;
    float diffuseStrength = 1.0;

    vec3 norm = (vec3(texture(texture1, fTex)) * 2.0 - 1.0);
    norm = fTBN * norm;
    vec3 lightDir = normalize(light.position - fPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diffuseStrength * diff * texture(texture0, fTex);

    vec3 viewDir = normalize(-fPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    vec4 specular = specularStrength * spec * texture(texture2, fTex);

    float distance = length(light.position - fPos);
    float attenuation = 1.0 / (light.attenuation_coefficient * distance * distance);

    FragColor = diffuse + specular;
    FragColor.a = 1.0;
}
