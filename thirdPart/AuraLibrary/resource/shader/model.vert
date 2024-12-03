#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec3 vsPos;
out vec3 vsNormal;
out vec2 vsTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vsNormal = mat3(transpose(inverse(model))) * aNormal;
    vec4 tmpPos =  model * vec4(aPos, 1.0);
    vsPos = tmpPos.xyz;
    vsTexCoord = aTexCoord;
    gl_Position = projection * view * tmpPos;

    //gl_PointSize = 10.0;
}
