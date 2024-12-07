#version 330 core
struct Material{
    sampler2D diffuse;
    vec3 ambient;
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
in vec2 vsTexCoord;

out vec4 FragColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    vec3 ambient = light.ambient * texture(material.diffuse,vsTexCoord).rgb;

    // diffuse
    vec3 norm = normalize(vsNormal);
    vec3 lightDir = normalize(light.position - vsPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse,vsTexCoord).rgb;

    // specular
    vec3 viewDir = normalize(viewPos - vsPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    vec3 result = (ambient + diffuse + specular);
    FragColor = vec4(result, 1.0);
    //FragColor = texture(material.diffuse,vsTexCoord);
}
