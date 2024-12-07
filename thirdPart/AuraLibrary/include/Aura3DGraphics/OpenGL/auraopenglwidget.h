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
    explicit AuraOpenGLWidget(std::shared_ptr<AuraOpenGLUnitManager> unitManager,std::shared_ptr<AuraOpenGLModelManager> modelManager =nullptr,QWidget *parent = nullptr);
    ~AuraOpenGLWidget();

    void initWidget(){
        m_shaderDir=AURA_LIBRARY_SHADER_DIR;
        m_moduleDir=AURA_LIBRARY_MODULE_DIR;
        m_textureDir=AURA_LIBRARY_TEXTURE_DIR;
    }

    void initWidget(const QString& shaderDir, const QString& moduleDir,const QString& textureDir);

public:
    //可以放至Aura3DGraphicsTool中
    double posXFromOpenGLToQt(double posX);//可提出去
    double posYFromOpenGLToQt(double posY);//可提出去
    double posXFromQtToOpenGL(double posX);//可提出去
    double posYFromQtToOpenGL(double posY);//可提出去

    std::shared_ptr<AuraOpenGLModelManager> modelManager()  const;
    std::shared_ptr<AuraOpenGLUnitManager>  unitManager()   const;

    //==========================context===================
    QOpenGLContext *mainContext() const;
    QSurface *surface() const;

    bool loadContextFlag() const;

    void setMainContext(QOpenGLContext *newMainContext);
    //==========================context===================

    bool modelInitFlag() const;
    void setModelInitFlag(bool newModelInitFlag);
public:
    //test
    void checkUnit();
protected:
    //init
    void initModel();
    void initVAOs();
    void updateContext();

    //draw
    void drawAxisXYZ(QOpenGLShaderProgram* shader);
    void drawCone(const QVector3D & pos,const QQuaternion& rotation );
    void useShader(QOpenGLShaderProgram* shader);

    //pick
    QRect getSelectRect(QPoint startPos,QPoint endPos); //可提出去
    QPair<bool,QVector<QVector3D>> checkSelectModel(const QVector3D & origPos,const QVector3D& rayDir,AuraOpenGLModel* model);
    bool checkSelectModel(const QRect& rect,AuraOpenGLModel* model);


    void initializeGL()override;
    void resizeGL(int w, int h)override;
    void paintGL()override;

    void keyPressEvent(QKeyEvent *e)override;
    void keyReleaseEvent(QKeyEvent*e)override;
    void wheelEvent(QWheelEvent * e)override;
    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent *e)override;
    void mouseReleaseEvent(QMouseEvent *e)override;
private:

    QVector<unsigned int*> m_vaos;
    int m_validVaoCount=0;

    QString m_shaderDir;
    QString m_moduleDir;
    QString m_textureDir;

    AuraOpenGLCamera * m_camera=nullptr;    //必要
    std::shared_ptr<AuraOpenGLUnitManager>  m_unitManager=nullptr;
    std::shared_ptr<AuraOpenGLModelManager> m_modelManager=nullptr;

    //mouse control
    QPoint m_startPoint;
    QPoint m_nowPoint;
    QPoint m_endPoint;
    QRect m_selectRect;

    //rubberband
    AuraRubberBand * m_rubberBand=nullptr;

    QOpenGLShaderProgram * m_nowShader=nullptr;

    bool m_modelInitFlag =false;

    bool m_drawBackgroundFlag;
    bool m_textShowFlag;

    bool m_drawBoundingBoxFlag;
    bool m_selectRectFlag;
    bool m_shiftFlag{false};

    bool m_loadContextFlag{false};
    bool m_sharedContextFlag{false};
    QOpenGLContext * m_mainContext{nullptr};
    QOpenGLContext * m_renderContext{nullptr};
    QSurface * m_surface{nullptr};



signals:

};

}//AuraUI

//===================废弃方案=============================

//void loadContext(QSurface* surface,QOpenGLContext* mainContext);
