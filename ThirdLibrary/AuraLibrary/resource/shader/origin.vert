#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 vsColor;
//out vec4 vsPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vsColor = vec3(0.8, 0.3, 0.2);
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    gl_PointSize = 10.0;
}
