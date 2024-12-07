#pragma once

#include <float.h>

#include <Eigen/Dense>
#include <QVector3D>
#include <QMatrix3x3>
#include <QMatrix4x4>

#include "../AuraGlobal.h"
//#include "fishswarmalgorithmtool.h"

#include <AuraTemplate/Singleton.hpp>
class QWidget;
namespace AuraTool {

struct Plane {
    QVector3D normal; // 法向量
    QVector3D point;  // 平面上一点
    float distance;   // 平面到原点的距离

public:
    Plane() {}
    Plane(const QVector3D &n, float d) : normal(n.normalized()), distance(d) {
        // 根据法向量和距离计算平面上一点
        point = n * (-d / n.lengthSquared());
    }
    Plane(const QVector3D &p, const QVector3D &n) : point(p), normal(n.normalized()) {
        // 根据平面上一点和法向量计算距离
        distance = -QVector3D::dotProduct(normal, point);
    }
};


//OBB包围盒
struct BoundingBoxOBB
{
    QVector3D center; // 中心点
    QMatrix3x3 axis;   // 三个轴 [[xx,yx,zx][xy,yy,zy][xz,yz,zz]]
    QVector3D extent; // 三个轴上的半径

};
//AABB包围盒
struct BoundingBoxAABB
{
    QVector3D max;
    QVector3D min;

public:
    BoundingBoxAABB() : max(QVector3D(0, 0, 0)), min(QVector3D(0, 0, 0)) {}
    BoundingBoxAABB(const QVector3D& min, const QVector3D& max) : max(max), min(min) {}
};

class AuraLibrary_DECL AuraAlgorithmTool
{

    SINGLETON_H(AuraAlgorithmTool)
    SINGLETON_H_CONSTRUCTOR(AuraAlgorithmTool)
public:

    //========================3DGraphics=========================================
    //设备坐标转换
    static double posXFromOpenGLToQt(double posX,QWidget* w);
    static double posYFromOpenGLToQt(double posY,QWidget* w);
    static double posXFromQtToOpenGL(double posX,QWidget* w);
    static double posYFromQtToOpenGL(double posY,QWidget* w);



    //射线法点选三角形
    /* Möller-Trumbore 算法 */
    static bool checkIntersectTriangle(const QVector3D& origPos, const QVector3D& rayDir,
                                       const QVector3D& v0, const QVector3D& v1, const QVector3D& v2,
                                       double *t, double *u, double *v, QVector3D &intersectionPoint);
    static bool checkIntersectOBB(const QVector3D &origPos, const QVector3D &rayDir, const BoundingBoxOBB &obb,QQuaternion modelRotation);
    static bool checkIntersectAABB(const QVector3D &origPos, const QVector3D &rayDir, const BoundingBoxAABB &aabb);

    //平面
    static Plane generatePlane(const QVector3D& p1,const QVector3D& p2,const QVector3D& p3);
    static QPair<bool,QVector3D> intersectRayWithPlane(const QVector3D &origPos, const QVector3D &rayDir, const Plane &plane);
    static QVector<Plane> generateBoundingBoxPlanes(const QVector<QVector3D> &points);

    // 包围盒
    //=OBB
    static BoundingBoxOBB generateOBB(const QVector<QVector3D>& points);
    static QVector<QVector3D> generateBoundingBoxPoints(const BoundingBoxOBB& obb);
    static QVector<Plane> generateBoundingBoxPlane(const BoundingBoxOBB& obb);
    static BoundingBoxOBB rotateBoundingBoxOBB(const BoundingBoxOBB &obb, const QQuaternion &rotation);
    static QVector<QVector3D> getBoundingBoxAxes(const BoundingBoxOBB &obb, QQuaternion modelRotation);
    //=AABB
    static QVector3D caculateAABBCenter(const BoundingBoxAABB& aabb);
    static QVector3D caculateAABBSize(const BoundingBoxAABB& aabb);
    static bool checkPointInAABB(const QVector3D& point,const BoundingBoxAABB& aabb);
    static BoundingBoxAABB generateAABB(const BoundingBoxAABB& aabb1,const BoundingBoxAABB& aabb2);
    static BoundingBoxAABB generateAABB(const QVector<QVector3D>& points);
    static QVector<QVector3D> generateBoundingBoxPoints(const BoundingBoxAABB& obb);


    //其它
    static QMatrix3x3 computeCovMatrix3D(const QVector<QVector3D>& points);
    static QVector3D computeMean3D(const QVector<QVector3D>& points);
    static QVector3D getVector3DFromColor(const QColor & color);
    static QRect getSelectRect(const QPoint& startPos,const QPoint& endPos);

    /*轴分离定理*/
    static bool intersectRayWithBoundingBox(const QVector3D &origPos, const QVector3D &rayDir, const QVector<QVector3D> &points, const QVector<QVector3D> &axes);
    static bool overlapOnAxis(const QVector3D &origPos, const QVector3D &rayDir, const QVector<QVector3D> &points, const QVector3D &axis);
    //========================3DGraphics=========================================








};

}//AuraTool
