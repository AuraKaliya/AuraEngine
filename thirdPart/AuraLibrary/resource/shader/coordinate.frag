#version 330 core
out vec4 FragColor;

in vec3 geoColor;



void main()
{
    FragColor =vec4(geoColor,1.0);
}
