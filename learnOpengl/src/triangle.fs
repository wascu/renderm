#version 330 core
out vec4 FragColor;

uniform vec4 vtxColor;
void main()
{
    FragColor = vtxColor;
}