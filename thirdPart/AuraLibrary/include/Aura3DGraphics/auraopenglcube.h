#pragma once

#include <QObject>


#include "auraopenglgeometry.h"


namespace AuraUI {
class AURAUI_LIB_DECL AuraOpenGLCube : public AuraOpenGLGeometry
{
    Q_OBJECT
public:
    explicit AuraOpenGLCube(QObject *parent = nullptr);
    void paint(QOpenGLShaderProgram* shader)override;

    float cubeSize() const;
    void setCubeSize(float newCubeSize);
private:
    float m_cubeSize;
signals:

};

}// namespace AuraUI
