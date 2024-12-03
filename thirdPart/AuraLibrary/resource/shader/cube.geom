#version 330 core
layout (points) in;
layout (triangle_strip, max_vertices = 36) out;

in vec3 vsColor[];
in vec4 vsPos[];
out vec3 geoColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float cubeSize;

void buildCube(vec4 pos, vec3 color)
{
    geoColor = color;

    mat4 mvp = projection *  view * model;

    vec4 vertices[8];
    vertices[0] = pos;
    vertices[1] = pos + vec4(cubeSize, 0.0, 0.0, 0.0);
    vertices[2] = pos + vec4(0.0, -cubeSize, 0.0, 0.0);
    vertices[3] = pos + vec4(cubeSize, -cubeSize, 0.0, 0.0);
    vertices[4] = pos + vec4(0.0, 0.0, -cubeSize, 0.0);
    vertices[5] = pos + vec4(cubeSize, 0.0, -cubeSize, 0.0);
    vertices[6] = pos + vec4(0.0, -cubeSize, -cubeSize, 0.0);
    vertices[7] = pos + vec4(cubeSize, -cubeSize, -cubeSize, 0.0);

    int indices[36]={
        0, 1, 2, 1, 3, 2,
        4, 5, 6, 5, 7, 6,
        0, 1, 4, 1, 5, 4,
        2, 3, 6, 3, 7, 6,
        0, 2, 4, 2, 6, 4,
        1, 3, 5, 3, 7, 5
    };

    for (int i = 0; i < 36; i++)
    {
        gl_Position = mvp * vertices[indices[i]];
        EmitVertex();
    }

    EndPrimitive();
}

void main()
{
    buildCube(vsPos[0], vsColor[0]);
}
