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

in vec3 geoColor;
in vec3 geoPos;
in vec3 geoNormal;

out vec4 FragColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // //ambient
    vec3 ambient = light.ambient *material.ambient;

    // //diffuse
    vec3 norm = normalize(geoNormal);
    vec3 lightDir = normalize(light.position - geoPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    // // specular
    vec3 viewDir = normalize(viewPos - geoPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);


    //FragColor = vec4(1.0,0.0,0.0, 1.0);
}
