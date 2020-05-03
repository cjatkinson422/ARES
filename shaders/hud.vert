#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
uniform float aspect;
uniform float x;
uniform float y;

out vec2 fTex;

void main()
{
   fTex = aTex;
   gl_Position = vec4((x + aPos.x)/aspect, (y + aPos.y), aPos.z, 1.0);

};
