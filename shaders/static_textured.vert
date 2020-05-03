#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec3 tangen;
layout (location = 4) in vec3 bitang;

uniform mat4 projection;
uniform mat4 model_matrix;

out vec3 fPos;
out mat3 fTBN;
out vec2 fTex;
out vec3 fNorm;

void main()
{

   fPos = vec3(model_matrix * vec4(aPos, 1.0));
   vec3 T = normalize(vec3(model_matrix * vec4(tangen, 0.0)));
   vec3 B = normalize(vec3(model_matrix * vec4(bitang, 0.0)));
   vec3 N = normalize(vec3(model_matrix * vec4(normal, 0.0)));
   fTBN = mat3(T,B,N);
   fTex = aTex;
   gl_Position = projection*model_matrix*vec4(aPos.x, aPos.y, aPos.z, 1.0);
};
