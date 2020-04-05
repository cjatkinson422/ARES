#version 430 core
layout (location = 0) in vec3 aPos;
uniform float aspect;
uniform float x;
uniform float y;
void main()
{
   gl_Position = vec4((x + aPos.x)/aspect, y + aPos.y, aPos.z, 1.0);

};
