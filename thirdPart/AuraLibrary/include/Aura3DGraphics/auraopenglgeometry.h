#pragma once

#include <QObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>
//#include <QOpenGLTexture>
//#include <glad/glad.h>
//#include <QOpenGLWidget>

#include "../AuraGlobal.h"
#include "AuraOpenGLEnumValue.h"

namespace AuraUI {
/*
    使用几何着色器构建实体， 类中只需存储几何体类型（base）、绘制坐标点集（base）、几何体参数（跟随类）。
    子类中需要实现需要实现 paint（Shader）即可。
    在paint中需要对几何体参数传入对应的shader中。
*/
/*
*/


//using OpenGLDrawFunction = void (*)(QOpenGLShaderProgram* ,const QVariant& value) ;
class AURAUI_LIB_DECL AuraOpenGLGeometry : public QObject,public QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit AuraOpenGLGeometry(QObject *parent = nullptr);
    void loadData(const QVector<double>& posList,const QVector<unsigned int> & indexList);
    void init(InitStratagy initStratagy = InitStratagy::PositionOnly);
    //void paint(QOpenGLShaderProgram* shader,const QVariant& value);
    virtual void paint(QOpenGLShaderProgram* shader);


protected:


    //OpenGLDrawFunction m_paintFunction;

    unsigned int m_vao;
    unsigned int m_vbo;
    unsigned int m_ebo;

    QVector<double> m_posList;
    QVector<unsigned int > m_indexList;

    bool m_initFlag;

signals:


};


//void PaintLine(QOpenGLShaderProgram* shader,const QVariant& value);
}// namespace AuraUI
