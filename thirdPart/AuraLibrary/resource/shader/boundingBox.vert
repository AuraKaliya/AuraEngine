#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 vsPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{

    vec4 tmpPos = projection * view * model * vec4(aPos, 1.0);
    vsPos = tmpPos.xyz;
    gl_Position = tmpPos;

    gl_PointSize =10;
}
