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

out vec4 FragColor;

in vec3 vsColor;
in vec4 vsPos;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    FragColor = vec4(vsColor,1.0);
}

