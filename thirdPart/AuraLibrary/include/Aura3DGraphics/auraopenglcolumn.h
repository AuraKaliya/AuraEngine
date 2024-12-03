#pragma once

#include <QObject>
#include "auraopenglgeometry.h"

namespace AuraUI {
class AURAUI_LIB_DECL AuraOpenGLColumn : public AuraOpenGLGeometry
{
    Q_OBJECT
public:
    explicit AuraOpenGLColumn(QObject *parent = nullptr);
    void paint(QOpenGLShaderProgram* shader)override;


    float columnRadius() const;
    void setColumnRadius(float newColumnRadius);

    float columnHeight() const;
    void setColumnHeight(float newColumnHeight);

private:
    float m_columnRadius;
    float m_columnHeight;
signals:

};
}// namespace AuraUI
