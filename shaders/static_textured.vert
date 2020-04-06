#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec2 aTex;
uniform mat4 projection;

out vec3 fPos;
out vec3 fNorm;
out vec2 fTex;

uniform mat4 transform;
void main()
{
   fPos = aPos;
   fNorm = aNorm;
   fTex = aTex;
   gl_Position = projection*vec4(aPos.x, aPos.y, aPos.z, 1.0);
};
