#pragma once

#include <QObject>
#include "auraopenglmodel.h"


#include <AuraGlobal.h>

namespace AuraUI {
class AURAUI_LIB_DECL AuraOpenGLGeometryBuilder : public QObject
{
    Q_OBJECT
public:
    explicit AuraOpenGLGeometryBuilder(QObject *parent = nullptr);
    static void createOneColumn(AuraOpenGLModel* obj,QVector3D pos,QVector3D direction,double radius,double height,unsigned int segment = 36);
    static void createOneCube(AuraOpenGLModel* obj,QVector3D centerPos,double roundRadius);
    static void createOneTorus(AuraOpenGLModel* obj, QVector3D centerPos, QVector3D normal, double tubeRadius, double torusRadius, unsigned int sides = 36, unsigned int rings = 36);
    static void createTorusSegment(AuraOpenGLModel * obj , QVector3D startPos, QVector3D endPos, QVector3D centerPos, double tubeRadius, unsigned int sides = 36, unsigned int rings = 36);

    static void createRound(AuraOpenGLModel * obj,QVector3D centerPos,QVector3D normal,double radius,unsigned int segment = 36);

    static void createLinkColumn(AuraOpenGLModel* obj,QVector<QVector3D> linkPosList,double radius,bool isClosed = false,unsigned int segment = 36);

    static void addCube(AuraOpenGLModel* obj,QVector3D startPos,QVector3D endPos,double width);
    static void addCube(AuraOpenGLModel *obj, QVector3D centerPos, double roundRadius);
    static void addColumn(AuraOpenGLModel* obj, QVector3D startPos,QVector3D endPos,double radius,unsigned int segment =36);
    static void addTorusSegment(AuraOpenGLModel * obj, QVector3D startPos, QVector3D endPos, QVector3D centerPos, double tubeRadius, unsigned int sides = 36, unsigned int rings = 36 );
    //static void addSphere(AuraOpenGLModel * obj,QVector3D);


    static double angleBetweenVectors(const QVector3D& vec1, const QVector3D& vec2) ;
signals:

};


}//AuraUI
