#pragma once

#include <QObject>

#include "auraopenglgeometry.h"

namespace AuraUI {


class AURAUI_LIB_DECL AuraOpenGLSyntheticGeometry : public AuraOpenGLGeometry
{
    Q_OBJECT
public:
    explicit AuraOpenGLSyntheticGeometry(QObject *parent = nullptr);
    void paint(QOpenGLShaderProgram* shader)override;


    //void setColumArgs(float radius);
    void setColumArgs(float radius,float height);
    void setTorusArgs(float tubeRadius,float torusRadius,QVector3D torusCenterPos);


    GeometryType type() const;
    void setType(GeometryType newType);

private:
    GeometryType m_type;

    //cuboid

    //column
    float m_columnRadius;
    float m_columnHeight;

    //torus
    float m_tubeRadius;
    float m_torusRadius;
    QVector3D m_torusCenterPos;
signals:

};
}// namespace AuraUI
