#pragma once

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLWindow>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include <AuraGlobal.h>

#include "AuraOpenGLEnumValue.h"




namespace AuraUI {
class AuraOpenGLModel;
class AuraOpenGLCamera;
class AuraOpenGLUnitManager;
class AuraOpenGLModelManager;

class AuraRubberBand;

class AURAUI_LIB_DECL AuraOpenGLWidget :public QOpenGLWidget,public QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit AuraOpenGLWidget(QWidget *parent = nullptr);
    //explicit AuraOpenGLWidget(QWindow *parent = nullptr);
    void initWidget(){
        qDebug()<<"AuraOpenGLWidget::initWidget | call.";
        m_shaderDir=AURA_LIBRARY_SHADER_DIR;
        m_moduleDir=AURA_LIBRARY_MODULE_DIR;
        m_textureDir=AURA_LIBRARY_TEXTURE_DIR;
    }

    QRect getSelectRect(QPoint startPos,QPoint endPos);
    QPair<bool,QVector<QVector3D>> checkSelectModel(const QVector3D & origPos,const QVector3D& rayDir,AuraOpenGLModel* model);
    bool checkSelectModel(const QRect& rect,AuraOpenGLModel* model);


    void initTest();

public:

    AuraOpenGLUnitManager *unitManager() const;

    double posXFromOpenGLToQt(double posX);
    double posYFromOpenGLToQt(double posY);
    double posXFromQtToOpenGL(double posX);
    double posYFromQtToOpenGL(double posY);

    void checkUnit();
    void initModel();

    AuraOpenGLModelManager *modelManager() const;

protected:
    void drawAxisXYZ(QOpenGLShaderProgram* shader);
    void drawCone(const QVector3D & pos,const QQuaternion& rotation );
    void useShader(QOpenGLShaderProgram* shader);

    void initializeGL()override;
    void resizeGL(int w, int h)override;
    void paintGL()override;
    void paintEvent(QPaintEvent* e)override;
    void keyPressEvent(QKeyEvent *e)override;
    void wheelEvent(QWheelEvent * e)override;
    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent *e)override;
    void mouseReleaseEvent(QMouseEvent *e)override;

private:
    QString m_shaderDir;
    QString m_moduleDir;
    QString m_textureDir;

    AuraOpenGLCamera * m_camera=nullptr;    //必要
    AuraOpenGLUnitManager * m_unitManager=nullptr;
    AuraOpenGLModelManager * m_modelManager=nullptr;

    //mouse control
    QPoint m_startPoint;
    QPoint m_nowPoint;
    QPoint m_endPoint;
    QRect m_selectRect;

    //rubberband
    AuraRubberBand * m_rubberBand=nullptr;

    //tmp --整个大的模型的整体旋转---内部的各模型都进行同样旋转
   //QQuaternion m_modelRotation;

    QOpenGLShaderProgram * m_nowShader=nullptr;

    bool m_drawBackgroundFlag;
    bool m_textShowFlag;
    bool m_modelInitFlag =false;
    bool m_drawBoundingBoxFlag;
    bool m_selectRectFlag;

signals:

};

}//AuraUI
