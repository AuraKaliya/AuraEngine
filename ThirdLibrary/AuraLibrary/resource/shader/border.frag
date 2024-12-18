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
in vec3 vsNormal;

out vec4 FragColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // // //ambient
    // vec3 ambient = light.ambient *material.ambient;

    // // //diffuse
    // vec3 norm = normalize(vsNormal);
    // vec3 lightDir = normalize(light.position - vsPos);
    // float diff = max(dot(norm, lightDir), 0.0);
    // vec3 diffuse = light.diffuse * (diff * material.diffuse);

    // // // specular
    // vec3 viewDir = normalize(viewPos - vsPos);
    // vec3 reflectDir = reflect(-lightDir, norm);
    // float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // vec3 specular = light.specular * (spec * material.specular);

    // vec3 result = ambient + diffuse + specular;
    FragColor = vec4(0.0,0.0,1.0, 1.0);
    //FragColor = vec4(1.0,1.0,0.0,1.0);
}
