#version 330 core
struct Material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 vsPos;

out vec4 FragColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;


void main()
{
    FragColor = vec4(1.0,1.0,0.0,1.0);
}



