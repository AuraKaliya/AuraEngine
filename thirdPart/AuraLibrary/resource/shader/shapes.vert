#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 vsColor;
out vec3 vsNormal;
out vec4 vsPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float pointSize;

void main()
{
    vsColor = vec3(0.3, 0.3, 0.1);
    vsPos = projection * view * model * vec4(aPos, 1.0);
    gl_Position = vsPos;

    gl_PointSize = pointSize;
}
