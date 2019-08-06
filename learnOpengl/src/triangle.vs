#version 330 core
layout (location = 0) in vec3 aPos;

//out vec4 vtxColor;

void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   //vtxColor =  vec4(1.0f, 0.5f, 0.2f, 1.0f);
}