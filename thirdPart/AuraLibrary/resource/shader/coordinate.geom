#version 330 core
layout (points) in;
layout (line_strip, max_vertices = 2) out;

in vec4 vsPos[];
in vec4 vsDirection[];
in vec3 vsColor[];

out vec3 geoColor;


uniform mat4 rotation;
uniform vec3 moveVector;

void buildCoordinate(vec4 pos, vec4 direction)
{
    // 轴
    gl_Position = vec4(vec3(pos) + moveVector, 1.0);
    geoColor = vsColor[0];
    EmitVertex();

    gl_Position = vec4(vec3(rotation * direction) + moveVector, 1.0);
    geoColor = vsColor[0];
    EmitVertex();

    EndPrimitive();
}


void main()
{
    geoColor = vsColor[0];
    buildCoordinate(vsPos[0],vsDirection[0]);
}
