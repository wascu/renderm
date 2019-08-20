#version 330 core
out vec4 FragColor;

in vec3 vtxColor;
void main()
{
    FragColor = vec4(vtxColor,1.0f);
}