#version 330 core
layout (points) in;
layout (triangle_strip, max_vertices = 42) out;

in vec4 vsPos[];
in vec4 vsDirection[];
in vec3 vsColor[];

out vec3 geoColor;
uniform mat4 rotation;
uniform vec3 moveVector;
uniform mat4 normalRotation;

mat4 rotateToPlane(vec4 direction)
{
    // 1. 标准化方向向量
    vec3 normalDirection = normalize(direction.xyz);

    // 2. 定义屏幕平面的法向量 (0, 0, 1)
    vec3 screenNormal = vec3(0.0, 0.0, 1.0);

    // 3. 计算旋转轴 (叉积)
    vec3 rotationAxis = cross(screenNormal, normalDirection);
    float sinAngle = length(rotationAxis); // 旋转轴的长度是 sin(夹角)
    float cosAngle = dot(screenNormal, normalDirection); // cos(夹角)

    // 4. 如果 normalDirection 和 screenNormal 平行，则不需要旋转
    if (sinAngle == 0.0)
    {
        return mat4(1.0);  // 返回单位矩阵
    }

    // 5. 归一化旋转轴
    rotationAxis = normalize(rotationAxis);

    // 6. 使用 Rodrigues 旋转公式构建旋转矩阵
    float x = rotationAxis.x;
    float y = rotationAxis.y;
    float z = rotationAxis.z;
    float omc = 1.0 - cosAngle;

    // Rodrigues 旋转矩阵
    mat4 rotationMatrix = mat4(
        cosAngle + x * x * omc,      x * y * omc - z * sinAngle, x * z * omc + y * sinAngle, 0.0,
        y * x * omc + z * sinAngle,  cosAngle + y * y * omc,      y * z * omc - x * sinAngle, 0.0,
        z * x * omc - y * sinAngle,  z * y * omc + x * sinAngle, cosAngle + z * z * omc,     0.0,
        0.0,                        0.0,                        0.0,                        1.0
    );

    return rotationMatrix;
}

void buildCoordinateArrow(vec4 pos, vec4 direction)
{
    const int numSides = 20;  // 圆锥底面边数
    const float radius = 0.027f;  // 圆锥底面半径
    const float height = 0.09f;  // 圆锥高度


    // 1. 计算圆锥底面中心点
    vec4 baseCenter = vec4(vec3(rotation * direction) + moveVector, 1.0); // 箭头起点
    // 2. 计算圆锥顶部点
    vec4 tip = baseCenter + height*direction;  // 箭头顶点在方向上延伸

    // 侧面法线基准向量
    //vec3 baseNormal = normalize(cross(rotatedDirection, vec3(0.0, 1.0, 0.0)));

    geoColor = vsColor[0];
    gl_Position = tip;  // 输出底面顶点
    EmitVertex();

    // 3. 生成圆锥侧面
    for (int i = 0; i <= numSides; i++)
    {
        // 当前角度
        float angle = 2.0 * 3.1415926 * float(i) / float(numSides);
        float nextAngle = 2.0 * 3.1415926 * float((i+1)%numSides) / float(numSides);

        // 计算旋转后的底面顶点偏移
        vec4 offsetPos = vec4(cos(angle) * radius, sin(angle) * radius, 0.0,1.0f);
        offsetPos = rotation*rotateToPlane(direction)*offsetPos;
        offsetPos =vec4(moveVector,1.0f)+ offsetPos;

        // 计算旋转后的底面顶点偏移
        vec4 nextOffsetPos = vec4(cos(angle) * radius, sin(angle) * radius, 0.0,1.0f);
        nextOffsetPos = rotation*rotateToPlane(direction)*nextOffsetPos;
        nextOffsetPos =vec4(moveVector,1.0f)+ nextOffsetPos;

        // 输出底面顶点和顶部点的三角形
        geoColor = vsColor[0];
        gl_Position = offsetPos,1.0f;  // 输出底面顶点
        EmitVertex();

        geoColor = vsColor[0];
        gl_Position = tip;  // 输出底面顶点
        EmitVertex();

        geoColor = vsColor[0];
        gl_Position = nextOffsetPos,1.0f;  // 输出底面顶点
        EmitVertex();
    }

//    // 4. 生成圆锥底面

//    // 底面中心点
//    geoColor = vsColor[0];
//    gl_Position=baseCenter;
//    EmitVertex();

//    for (int i = 0; i < numSides; i++)
//    {
//        // 当前角度
//        float angle = 2.0 * 3.1415926 * float(i) / float(numSides);

//        // 计算底面顶点偏移
//        vec4 offsetPos = vec4(cos(angle) * radius, sin(angle) * radius, 0.0,1.0f);
//        offsetPos = rotation*rotateToPlane(direction)*offsetPos;
//        offsetPos =vec4(moveVector,1.0f)+ offsetPos;

//        geoColor = vsColor[0];
//        gl_Position = offsetPos;   // 输出底面中心点
//        EmitVertex();
//    }
    EndPrimitive();  // 结束一个图元
}

void main()
{
    geoColor = vsColor[0];
    buildCoordinateArrow(vsPos[0], vsDirection[0]);
}
