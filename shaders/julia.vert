#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec2 aTex;
uniform mat4 projection;

out vec3 fPos;
out vec3 aCol;

void main()
{
   gl_Position = projection*vec4(aPos.x, aPos.y, aPos.z, 1.0);

   aCol = vec3(aPos.x,aPos.y,aPos.z);

   fPos = aPos;

};
