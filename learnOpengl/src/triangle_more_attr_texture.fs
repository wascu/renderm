#version 330 core
out vec4 FragColor;

in vec3 vtxColor;
in vec2 texCoord;

//texture sampler
uniform sampler2D texture1;

void main()
{
    //FragColor = vec4(vtxColor,1.0f);
    FragColor = texture(texture1, texCoord);
}