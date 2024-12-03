#pragma once

#include <float.h>

#include <Eigen/Dense>
#include <QVector3D>
#include <QMatrix3x3>
#include <QMatrix4x4>

#include "../AuraGlobal.h"
#include "fishswarmalgorithmtool.h"

namespace AuraTool {

//OBB包围盒
struct BoundingBoxOBB
{
    QVector3D center; // 中心点
    QMatrix3x3 axis;   // 三个轴
    QVector3D extent; // 三个轴上的半径
};


class AURAUI_LIB_DECL AuraAlgorithmTool
{
public:
    AuraAlgorithmTool();

    /* Möller-Trumbore 算法 */
    static bool checkIntersectTriangle(const QVector3D& origPos, const QVector3D& rayDir,
                                       const QVector3D& v0, const QVector3D& v1, const QVector3D& v2,
                                       double *t, double *u, double *v, QVector3D &intersectionPoint);

    static BoundingBoxOBB generateOBB(const QVector<QVector3D>& points);
    static QVector<QVector3D>generateBoundingBoxPoints(const BoundingBoxOBB& obb);
    static QMatrix3x3 computeCovMatrix3D(const QVector<QVector3D>& points);
    static QVector3D computeMean3D(const QVector<QVector3D>& points);
    static QVector3D getVector3DFromColor(const QColor & color);

};

}//AuraTool
