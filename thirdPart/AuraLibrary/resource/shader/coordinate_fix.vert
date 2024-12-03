#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aDirection;
layout (location = 2) in vec3 aColor;

out vec3 vsColor;
out vec4 vsPos;
out vec4 vsDirection;

uniform float pointSize;

void main()
{
    vsPos =vec4(aPos, 1.0);
    vsColor = aColor;
    vsDirection = vec4(aDirection,1.0);

    gl_Position = vsPos;
    //gl_PointSize = pointSize;
    gl_PointSize = 5.0f;
}
