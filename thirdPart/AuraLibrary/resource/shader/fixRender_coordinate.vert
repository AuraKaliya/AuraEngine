#version 330 core
layout(location = 0) in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 moveVector;

void main()
{
    vec4 tmpPos  =/*projection * view **/ model *vec4(position, 1.0);
    tmpPos = tmpPos + vec4(-1.5f,-1.5f,0.0f,1.0f);
    gl_Position =tmpPos;
            //=vec4((vec3(projection * view * model *vec4(position, 1.0))+moveVector),1.0f);

}
