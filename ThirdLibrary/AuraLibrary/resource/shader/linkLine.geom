#version 330 core
layout (points) in;
layout (line_strip, max_vertices = 2) out;

in vec3 vsColor[];
in vec4 vsPos[];
in vec4 vsLinkPos[];
out vec3 geoColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void buildLine(vec4 basePos,vec4 linkPos,vec3 color)
{
    geoColor = color;

    mat4 mvp = projection *  view * model;

    gl_Position = mvp*basePos;
    EmitVertex();

    gl_Position = mvp*linkPos;
    EmitVertex();

    EndPrimitive();
}

void main()
{
    buildLine(vsPos[0],vsLinkPos[0], vsColor[0]);
}
