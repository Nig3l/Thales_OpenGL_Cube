#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 outColor;

uniform sampler2D ourTexture;

void main()
{
    if(TexCoord.x == 0.0 && TexCoord.y == 0){
        FragColor = vec4(outColor, 1.0);
    } else {
        FragColor = texture(ourTexture, TexCoord);
    }
}