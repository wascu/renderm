#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture1;

uniform bool force_white;

void main()
{
    if(force_white){
        FragColor = vec4(1.0,1.0,1.0,1.0);
        return;
    }
    if(abs(TexCoords.x -0.35)<0.02){
        FragColor=vec4(1.0,0.0,0.0,1.0);
    }else{
        FragColor = texture(texture1, TexCoords);
    }


}
