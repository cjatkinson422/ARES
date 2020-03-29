 #version 430 core
layout (location = 0) in vec3 aPos;
out vec3 fPos;

uniform mat4 transform;
void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   fPos = aPos;

};
