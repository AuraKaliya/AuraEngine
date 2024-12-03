#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 vsPos;
out vec3 vsNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vsNormal = mat3(transpose(inverse(model))) * aNormal;
    vec4 tmpPos = projection * view * model * vec4(aPos, 1.0);
    vsPos = tmpPos.xyz;
    gl_Position = tmpPos;

    gl_PointSize = 10.0;
}
