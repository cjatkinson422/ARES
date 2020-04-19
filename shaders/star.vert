#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec2 aTex;
uniform mat4 projection;
uniform mat4 model_matrix;

out vec3 fPos;
out vec3 fNorm;
out vec2 fTex;


void main()
{
   fPos = aPos;
   fNorm = aNorm;
   fTex = aTex;
   gl_Position = projection*model_matrix*vec4(aPos.x, aPos.y, aPos.z, 1.0);
};
