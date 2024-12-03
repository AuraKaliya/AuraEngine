#version 330 core
//layout (points) in;
//layout (triangle_strip, max_vertices = 256) out;

//in vec3 vsColor[];
//in vec4 vsPos[];
//in vec4 vsLinkPos[];

//out vec3 geoColor;
//out vec3 geoNormal;
//out vec3 geoPos;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//uniform float tubeRadius;
//uniform float torusRadius;
//uniform vec3 torusCenterPos;

//const int sides = 16;
//const int rings = 16;

//void buildTorus(vec4 startPos, vec4 endPos, vec3 centerPos, vec3 color) {
//    float startAngle = atan(startPos.y - centerPos.y, startPos.x - centerPos.x);
//    float endAngle = atan(endPos.y - centerPos.y, endPos.x - centerPos.x);

//    if (startAngle <= 0.0) startAngle += 2.0 * 3.14159265359;
//    if (endAngle <= 0.0) endAngle += 2.0 * 3.14159265359;

//    float ringStep = (endAngle - startAngle) / float(rings);
//    float sideStep = 2.0 * 3.14159265359 / float(sides);

//    for (int ring = 0; ring <= rings; ++ring) {
//        float ringAngle = startAngle + float(ring) * ringStep;
//        vec3 ringCenter = centerPos + vec3(torusRadius * cos(ringAngle), torusRadius * sin(ringAngle), 0.0);

//        for (int side = 0; side <= sides; ++side) {
//            float sideAngle = float(side) * sideStep;
//            vec3 vertex = ringCenter + vec3(tubeRadius * cos(sideAngle) * cos(ringAngle), tubeRadius * cos(sideAngle) * sin(ringAngle), tubeRadius * sin(sideAngle));
//            vec3 normal = normalize(vec3(cos(sideAngle) * cos(ringAngle), cos(sideAngle) * sin(ringAngle), sin(sideAngle)));

//            geoColor = color;
//            geoNormal = normal;
//            geoPos = vec3(model * vec4(vertex, 1.0));
//            gl_Position = projection * view * model * vec4(vertex, 1.0);
//            EmitVertex();
//        }
//    }
//    EndPrimitive();
//}
//void main() {
//    buildTorus(vsPos[0], vsLinkPos[0],torusCenterPos, vsColor[0]);
//}
layout (points) in;
layout (triangle_strip, max_vertices = 256) out;

in vec3 vsColor[];
in vec4 vsPos[];
in vec4 vsLinkPos[];

out vec3 geoColor;
out vec3 geoNormal;
out vec3 geoPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float tubeRadius;
uniform float torusRadius;
uniform vec3 torusCenterPos;

const int sides = 16;
const int rings = 8;

float atan2(float y, float x) {
    if (x > 0.0) return atan(y / x);
    if (x < 0.0) return atan(y / x) + 3.14159265359;
    if (y > 0.0) return 3.14159265359 / 2.0;
    if (y < 0.0) return -3.14159265359 / 2.0;
    return 0.0;
}

void buildTorus(vec4 startPos, vec4 endPos, vec3 centerPos, vec3 color) {
    float startAngle = atan2(startPos.y - centerPos.y, startPos.x - centerPos.x);
    float endAngle = atan2(endPos.y - centerPos.y, endPos.x - centerPos.x);

    if (startAngle <= 0.0) startAngle += 2.0 * 3.14159265359;
    if (endAngle <= 0.0) endAngle += 2.0 * 3.14159265359;

    float ringStep = (endAngle - startAngle) / float(rings);
    float sideStep = 2.0 * 3.14159265359 / float(sides);

    for (int ring = 0; ring < rings; ++ring) {
        float ringAngle = startAngle + float(ring) * ringStep;
        vec3 ringCenter = centerPos + vec3(torusRadius * cos(ringAngle), torusRadius * sin(ringAngle), 0.0);

        float nextRingAngle = startAngle + float((ring + 1) % (rings + 1)) * ringStep;
        vec3 nextRingCenter = centerPos + vec3(torusRadius * cos(nextRingAngle), torusRadius * sin(nextRingAngle), 0.0);

        for (int side = 0; side <= sides; ++side) {
            float sideAngle = float(side) * sideStep;
            vec3 vertex = ringCenter + vec3(tubeRadius * cos(sideAngle) * cos(ringAngle), tubeRadius * cos(sideAngle) * sin(ringAngle), tubeRadius * sin(sideAngle));
            vec3 normal = normalize(vec3(cos(sideAngle) * cos(ringAngle), cos(sideAngle) * sin(ringAngle), sin(sideAngle)));

            vec3 nextVertex = nextRingCenter + vec3(tubeRadius * cos(sideAngle) * cos(nextRingAngle), tubeRadius * cos(sideAngle) * sin(nextRingAngle), tubeRadius * sin(sideAngle));
            vec3 nextNormal = normalize(vec3(cos(sideAngle) * cos(nextRingAngle), cos(sideAngle) * sin(nextRingAngle), sin(sideAngle)));

            geoColor = color;
            geoNormal = normal;
            geoPos = vec3(model * vec4(vertex, 1.0));
            gl_Position = projection * view * model * vec4(vertex, 1.0);
            EmitVertex();

            geoColor = color;
            geoNormal = nextNormal;
            geoPos = vec3(model * vec4(nextVertex, 1.0));
            gl_Position = projection * view * model * vec4(nextVertex, 1.0);
            EmitVertex();
        }
        EndPrimitive();
    }
}

//void buildTorus(vec4 startPos, vec4 endPos, vec3 centerPos, vec3 color) {
//    float startAngle = atan2(startPos.y - centerPos.y, startPos.x - centerPos.x);
//    float endAngle = atan2(endPos.y - centerPos.y, endPos.x - centerPos.x);

//    if (startAngle <= 0.0) startAngle += 2.0 * 3.14159265359;
//    if (endAngle <= 0.0) endAngle += 2.0 * 3.14159265359;

//    float ringStep = (endAngle - startAngle) / float(rings);
//    float sideStep = 2.0 * 3.14159265359 / float(sides);

//    for (int ring = 0; ring <= rings; ++ring) {
//        float ringAngle = startAngle + float(ring) * ringStep;
//        vec3 ringCenter = centerPos + vec3(torusRadius * cos(ringAngle), torusRadius * sin(ringAngle), 0.0);

//        float nextRingAngle = startAngle + float(ring+1) * ringStep;
//        vec3 nextRingCenter = centerPos + vec3(torusRadius * cos(nextRingAngle), torusRadius * sin(nextRingAngle), 0.0);

//        for (int side = 0; side <= sides; ++side) {
//            float sideAngle = float(side) * sideStep;
//            vec3 vertex = ringCenter + vec3(tubeRadius * cos(sideAngle) * cos(ringAngle), tubeRadius * cos(sideAngle) * sin(ringAngle), tubeRadius * sin(sideAngle));
//            vec3 normal = normalize(vec3(cos(sideAngle) * cos(ringAngle), cos(sideAngle) * sin(ringAngle), sin(sideAngle)));

//            vec3 nextVertex = nextRingCenter+vec3(tubeRadius * cos(sideAngle) * cos(nextRingAngle), tubeRadius * cos(sideAngle) * sin(nextRingAngle), tubeRadius * sin(sideAngle));
//            vec3 nextNormal = normalize(vec3(cos(sideAngle) * cos(nextRingAngle), cos(sideAngle) * sin(nextRingAngle), sin(sideAngle)));

//            geoColor = color;
//            geoNormal = normal;
//            geoPos = vec3(model * vec4(vertex, 1.0));
//            gl_Position = projection * view * model * vec4(vertex, 1.0);
//            EmitVertex();

//            geoColor = color;
//            geoNormal = nextNormal;
//            geoPos = vec3(model * vec4(nextVertex, 1.0));
//            gl_Position = projection * view * model * vec4(nextVertex, 1.0);
//            EmitVertex();
//        }
//        EndPrimitive();
//    }
//}

//void buildTorus(vec4 startPos, vec4 endPos, vec3 centerPos, vec3 color) {
//    float startAngle = atan2(startPos.y - centerPos.y, startPos.x - centerPos.x);
//    float endAngle = atan2(endPos.y - centerPos.y, endPos.x - centerPos.x);

//    if (startAngle <= 0.0) startAngle += 2.0 * 3.14159265359;
//    if (endAngle <= 0.0) endAngle += 2.0 * 3.14159265359;

//    float ringStep = (endAngle - startAngle) / float(rings);
//    float sideStep = 2.0 * 3.14159265359 / float(sides);

//    for (int ring = 0; ring <= rings; ++ring) {
//        float ringAngle = startAngle + float(ring) * ringStep;
//        vec3 ringCenter = centerPos + vec3(torusRadius * cos(ringAngle), torusRadius * sin(ringAngle), 0.0);

//        for (int side = 0; side <= sides; ++side) {
//            float sideAngle = float(side) * sideStep;
//            vec3 vertex = ringCenter + vec3(tubeRadius * cos(sideAngle) * cos(ringAngle), tubeRadius * cos(sideAngle) * sin(ringAngle), tubeRadius * sin(sideAngle));
//            vec3 normal = normalize(vec3(cos(sideAngle) * cos(ringAngle), cos(sideAngle) * sin(ringAngle), sin(sideAngle)));

//            geoColor = color;
//            geoNormal = normal;
//            geoPos = vec3(model * vec4(vertex, 1.0));
//            gl_Position = projection * view * model * vec4(vertex, 1.0);
//            EmitVertex();
//        }
//        EndPrimitive();
//    }
//}
void main() {
    buildTorus(vsPos[0], vsLinkPos[0], torusCenterPos, vsColor[0]);
}
