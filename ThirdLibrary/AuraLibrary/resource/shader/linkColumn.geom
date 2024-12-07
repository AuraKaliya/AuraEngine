#version 330 core
//layout (points) in;
//layout (triangle_strip, max_vertices = 160) out;

//in vec3 vsColor[];
//in vec4 vsPos[];
//in vec4 vsLinkPos[];
//out vec3 geoColor;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//uniform float columnRadius;
//const int segments = 20; // 圆柱体的圆周上使用的段数

//void buildColumn(vec4 basePos, vec4 linkPos, vec3 color)
//{
//    geoColor = color;

//    mat4 mvp = projection * view * model;

//    vec3 basePosition = basePos.xyz;
//    vec3 linkPosition = linkPos.xyz;
//    vec3 upDirection = normalize(linkPosition - basePosition);

//    // 确保右方向不是零向量
//    vec3 rightDirection;
//    if(abs(dot(upDirection, vec3(0.0, 1.0, 0.0))) > 0.99) {
//        rightDirection = normalize(cross(upDirection, vec3(1.0, 0.0, 0.0)));
//    } else {
//        rightDirection = normalize(cross(upDirection, vec3(0.0, 1.0, 0.0)));
//    }

//    vec3 forwardDirection = normalize(cross(rightDirection, upDirection));

//    vec4 bottomCenter = vec4(basePosition, 1.0);
//    vec4 topCenter = vec4(linkPosition, 1.0);

//    for(int i = 0; i <= segments; ++i)
//    {
//        float angle = 2.0 * 3.1415926 * float(i) / float(segments);
//        vec3 offset = columnRadius * (cos(angle) * rightDirection + sin(angle) * forwardDirection);

//        vec4 bottomVertex = vec4(basePosition + offset, 1.0);
//        vec4 topVertex = vec4(linkPosition + offset, 1.0);

//        // 绘制柱体
//        gl_Position = mvp * bottomVertex;
//        EmitVertex();

//        gl_Position = mvp * topVertex;
//        EmitVertex();

//        // 绘制底盖
//        if (i > 0) {
//            gl_Position = mvp * bottomCenter;
//            EmitVertex();

//            gl_Position = mvp * bottomVertex;
//            EmitVertex();

//            gl_Position = mvp * vec4(basePosition + columnRadius * (cos(angle - 2.0 * 3.1415926 / float(segments)) * rightDirection + sin(angle - 2.0 * 3.1415926 / float(segments)) * forwardDirection), 1.0);
//            EmitVertex();
//        }

//        // 绘制顶盖
//        if (i > 0) {
//            gl_Position = mvp * topCenter;
//            EmitVertex();

//            gl_Position = mvp * topVertex;
//            EmitVertex();

//            gl_Position = mvp * vec4(linkPosition + columnRadius * (cos(angle - 2.0 * 3.1415926 / float(segments)) * rightDirection + sin(angle - 2.0 * 3.1415926 / float(segments)) * forwardDirection), 1.0);
//            EmitVertex();
//        }
//    }

//    EndPrimitive();
//}



//void buildColumn(vec4 basePos, vec4 linkPos, vec3 color)
//{
//    geoColor = color;

//    mat4 mvp = projection * view * model;

//    vec3 basePosition = basePos.xyz;
//    vec3 linkPosition = linkPos.xyz;
//    vec3 upDirection = normalize(linkPosition - basePosition);

//    // 确保右方向不是零向量
//    vec3 rightDirection;
//    if(abs(dot(upDirection, vec3(0.0, 1.0, 0.0))) > 0.99) {
//        rightDirection = normalize(cross(upDirection, vec3(1.0, 0.0, 0.0)));
//    } else {
//        rightDirection = normalize(cross(upDirection, vec3(0.0, 1.0, 0.0)));
//    }

//    vec3 forwardDirection = normalize(cross(rightDirection, upDirection));

//    for(int i = 0; i <= segments; ++i)
//    {
//        float angle = 2.0 * 3.1415926 * float(i) / float(segments);
//        vec3 offset = columnRadius * (cos(angle) * rightDirection + sin(angle) * forwardDirection);

//        vec4 bottomVertex = vec4(basePosition + offset, 1.0);
//        vec4 topVertex = vec4(linkPosition + offset, 1.0);

//        gl_Position = mvp * bottomVertex;
//        EmitVertex();

//        gl_Position = mvp * topVertex;
//        EmitVertex();
//    }

//    EndPrimitive();
//}


//void buildColumn(vec4 basePos, vec4 linkPos, vec3 color)
//{
//    geoColor = color;

//    mat4 mvp = projection * view * model;

//    vec4 baseCenter = basePos;
//    vec4 linkCenter = linkPos;

//    vec4 disVertex = linkCenter-baseCenter;

//    for(int i = 0; i <= segments; ++i)
//    {
//        float angle = 2.0 * 3.1415926 * float(i) / float(segments);
//        float nextAngle = 2.0 * 3.1415926 * float(i + 1) / float(segments);

//        vec4 baseVertex = baseCenter + vec4(columnRadius * cos(angle), 0.0, columnRadius * sin(angle), 0.0);
//        vec4 nextBaseVertex = baseCenter + vec4(columnRadius * cos(nextAngle), 0.0, columnRadius * sin(nextAngle), 0.0);

//        vec4 topVertex = baseVertex+disVertex;
//        vec4 nextTopVertex = nextBaseVertex + disVertex;

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

layout (points) in;
layout (triangle_strip, max_vertices = 160) out;

in vec3 vsColor[];
in vec4 vsPos[];
in vec4 vsLinkPos[];

out vec3 geoColor;
out vec3 geoNormal;
out vec3 geoPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float columnRadius;
const int segments = 20; // 圆柱体的圆周上使用的段数

void buildColumn(vec4 basePos, vec4 linkPos, vec3 color)
{
    geoColor = color;

    mat4 mvp = projection * view * model;

    vec3 basePosition = basePos.xyz;
    vec3 linkPosition = linkPos.xyz;
    vec3 upDirection = normalize(linkPosition - basePosition);

    // 确保右方向不是零向量
    vec3 rightDirection;
    if(abs(dot(upDirection, vec3(0.0, 1.0, 0.0))) > 0.99) {
        rightDirection = normalize(cross(upDirection, vec3(1.0, 0.0, 0.0)));
    } else {
        rightDirection = normalize(cross(upDirection, vec3(0.0, 1.0, 0.0)));
    }

    vec3 forwardDirection = normalize(cross(rightDirection, upDirection));

    vec4 bottomCenter = vec4(basePosition, 1.0);
    vec4 topCenter = vec4(linkPosition, 1.0);

    for(int i = 0; i <= segments; ++i)
    {
        float angle = 2.0 * 3.1415926 * float(i) / float(segments);
        vec3 offset = columnRadius * (cos(angle) * rightDirection + sin(angle) * forwardDirection);

        vec4 bottomVertex = vec4(basePosition + offset, 1.0);
        vec4 topVertex = vec4(linkPosition + offset, 1.0);

        // 计算法向量
        vec3 normal = normalize(cross(topVertex.xyz - bottomVertex.xyz, rightDirection));

        geoPos = bottomVertex.xyz;
        geoNormal = normal;
        gl_Position = mvp * bottomVertex;
        EmitVertex();

        geoPos = topVertex.xyz;
        geoNormal = normal;
        gl_Position = mvp * topVertex;
        EmitVertex();

        // 绘制底盖
        if (i > 0) {
            geoPos = bottomCenter.xyz;
            geoNormal = vec3(mvp *vec4(vec3(0.0, -1.0, 0.0),1.0));
            gl_Position = mvp * bottomCenter;
            EmitVertex();

            geoPos = bottomVertex.xyz;
            geoNormal = vec3(mvp *vec4(vec3(0.0, -1.0, 0.0),1.0));
            gl_Position = mvp * bottomVertex;
            EmitVertex();

            vec4 prevBottomVertex = vec4(basePosition + columnRadius * (cos(angle - 2.0 * 3.1415926 / float(segments)) * rightDirection + sin(angle - 2.0 * 3.1415926 / float(segments)) * forwardDirection), 1.0);
            geoPos = prevBottomVertex.xyz;
            geoNormal = vec3(mvp *vec4(vec3(0.0, -1.0, 0.0),1.0));
            gl_Position = mvp * prevBottomVertex;
            EmitVertex();
        }

        // 绘制顶盖
        if (i > 0) {
            geoPos = topCenter.xyz;
            geoNormal = vec3(mvp *vec4(vec3(0.0, 1.0, 0.0),1.0));
            gl_Position = mvp * topCenter;
            EmitVertex();

            geoPos = topVertex.xyz;
            geoNormal = vec3(mvp *vec4(vec3(0.0, 1.0, 0.0),1.0));
            gl_Position = mvp * topVertex;
            EmitVertex();

            vec4 prevTopVertex = vec4(linkPosition + columnRadius * (cos(angle - 2.0 * 3.1415926 / float(segments)) * rightDirection + sin(angle - 2.0 * 3.1415926 / float(segments)) * forwardDirection), 1.0);
            geoPos = prevTopVertex.xyz;
            geoNormal = vec3(mvp *vec4(vec3(0.0, 1.0, 0.0),1.0));
            gl_Position = mvp * prevTopVertex;
            EmitVertex();
        }
    }

    EndPrimitive();
}

void main()
{
    buildColumn(vsPos[0], vsLinkPos[0], vsColor[0]);
}
