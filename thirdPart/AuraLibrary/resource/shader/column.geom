#version 330 core
//layout (points) in;
//layout (triangle_strip, max_vertices = 80) out;

//in vec3 vsColor[];
//in vec4 vsPos[];
//out vec3 geoColor;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//uniform float columnRadius;
//uniform float columnHeight;
//const int segments = 20; // 圆柱体的圆周上使用的段数

////最后输出的点的计算方法好像跟vert的不搭配

//void buildColumn(vec4 basePos, vec3 color)
//{
//    geoColor = color;

//    mat4 mvp = projection * view * model;

//    vec4 topCenter = basePos + vec4(0.0, columnHeight, 0.0, 0.0); // 顶部中心点

//    for (int i = 0; i <= segments; i++)
//    {
//        float angle = 2.0 * 3.1415926 * float(i) / float(segments);
//        float nextAngle = 2.0 * 3.1415926 * float(i + 1) / float(segments);
//        vec4 baseVertex = basePos + vec4(columnRadius * cos(angle), 0.0, columnRadius * sin(angle), 0.0);
//        vec4 nextBaseVertex = basePos + vec4(columnRadius * cos(nextAngle), 0.0, columnRadius * sin(nextAngle), 0.0);

//        vec4 topVertex = baseVertex + vec4(0.0, columnHeight, 0.0, 0.0);
//        vec4 nextTopVertex = nextBaseVertex + vec4(0.0, columnHeight, 0.0, 0.0);

//        gl_Position = mvp * baseVertex;
//        EmitVertex();

//        gl_Position = mvp * nextBaseVertex;
//        EmitVertex();

//        gl_Position = mvp * topVertex;
//        EmitVertex();

//        gl_Position = mvp * nextTopVertex;
//        EmitVertex();

//    }
//    EndPrimitive();
//}

//void main()
//{
//    buildColumn(vsPos[0], vsColor[0]);
//}
layout (points) in;
layout (triangle_strip, max_vertices = 80) out;

in vec3 vsColor[];
in vec4 vsPos[];

out vec3 geoColor;
out vec3 geoNormal;
out vec3 geoPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float columnRadius;
uniform float columnHeight;
const int segments = 20; // 圆柱体的圆周上使用的段数

void buildColumn(vec4 basePos, vec3 color)
{
    geoColor = color;

    mat4 mvp = projection * view * model;

    vec4 topCenter = basePos + vec4(0.0, columnHeight, 0.0, 0.0); // 顶部中心点

    for (int i = 0; i <= segments; i++)
    {
        float angle = 2.0 * 3.1415926 * float(i) / float(segments);
        float nextAngle = 2.0 * 3.1415926 * float(i + 1) / float(segments);
        vec4 baseVertex = basePos + vec4(columnRadius * cos(angle), 0.0, columnRadius * sin(angle), 0.0);
        vec4 nextBaseVertex = basePos + vec4(columnRadius * cos(nextAngle), 0.0, columnRadius * sin(nextAngle), 0.0);

        vec4 topVertex = baseVertex + vec4(0.0, columnHeight, 0.0, 0.0);
        vec4 nextTopVertex = nextBaseVertex + vec4(0.0, columnHeight, 0.0, 0.0);

        // 计算法向量
        vec3 normal = normalize(cross(nextBaseVertex.xyz - baseVertex.xyz, topVertex.xyz - baseVertex.xyz));

        geoPos = baseVertex.xyz;
        geoNormal = normal;
        gl_Position = mvp * baseVertex;
        EmitVertex();

        geoPos = nextBaseVertex.xyz;
        geoNormal = normal;
        gl_Position = mvp * nextBaseVertex;
        EmitVertex();

        geoPos = topVertex.xyz;
        geoNormal = normal;
        gl_Position = mvp * topVertex;
        EmitVertex();

        geoPos = nextTopVertex.xyz;
        geoNormal = normal;
        gl_Position = mvp * nextTopVertex;
        EmitVertex();
    }
    EndPrimitive();
}

void main()
{
    buildColumn(vsPos[0], vsColor[0]);
}
