#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in mat3 aNTB;
uniform mat4 projection;
uniform mat4 model_matrix;

out vec3 fPos;
out mat3 fNTB;
out vec2 fTex;


void main()
{
   fPos = aPos;
   fNTB = mat3(model_matrix) * aNTB;
   fTex = aTex;
   gl_Position = projection*model_matrix*vec4(aPos.x, aPos.y, aPos.z, 1.0);
};
