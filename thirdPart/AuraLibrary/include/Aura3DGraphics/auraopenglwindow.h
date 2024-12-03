#pragma once

#include <QWidget>
#include <QOpenGLWindow>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include <AuraUIWidget/UIHeader.h>
#include <AuraUIWidget/aurarubberband.h>

#include "auraopenglcamera.h"
#include "auraopenglshadermanager.h"
#include "auraopenglgeometrybuilder.h"
#include "auraopenglunitmanager.h"
#include "auraopenglgeometry.h"
#include "auraopenglcube.h"
#include "auraopenglcolumn.h"
#include "auraopenglsyntheticgeometry.h"
#include "auraopenglmodel.h"
#include "auraopenglmodelmanager.h"

#include <AuraAlgorithm/auraalgorithmtool.h>

namespace AuraUI {


class AURAUI_LIB_DECL AuraOpenGLWindow :public QOpenGLWindow,public QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit AuraOpenGLWindow(QWindow *parent = nullptr);
    //explicit AuraOpenGLWindow(QWindow *parent = nullptr);
    void initWindow(){
        qDebug()<<"AuraOpenGLWindow::initWindow | call.";
        m_shaderDir=AURAUI_SHADER_DIR;
        m_moduleDir=AURAUI_MODULE_DIR;
    }

    QRect getSelectRect(QPoint startPos,QPoint endPos);
    QPair<bool,QVector<QVector3D>> checkSelectModel(const QVector3D & origPos,const QVector3D& rayDir,AuraOpenGLModel* model);

public:

    AuraOpenGLUnitManager *unitManager() const;

    double posXFromOpenGLToQt(double posX);
    double posYFromOpenGLToQt(double posY);
    double posXFromQtToOpenGL(double posX);
    double posYFromQtToOpenGL(double posY);

    void checkUnit();
    void initModel();

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

    //QOpenGLContext *m_context;

    QString m_shaderDir;
    QString m_moduleDir;

    AuraOpenGLCamera * m_camera=nullptr;    //必要
    AuraOpenGLUnitManager * m_unitManager=nullptr;
    AuraOpenGLModelManager * m_modelManager=nullptr;

    //mouse control
    QPoint m_startPoint;
    QPoint m_nowPoint;
    QPoint m_endPoint;
    QRect m_selectRect;

    //tmp --整个大的模型的整体旋转---内部的各模型都进行同样旋转
    QQuaternion m_modelRotation;

    QOpenGLShaderProgram * m_nowShader=nullptr;

    bool m_drawBackgroundFlag;
    bool m_textShowFlag;
    bool m_modelInitFlag =false;
    bool m_drawBoundingBoxFlag;
    bool m_selectRectFlag;
signals:

};

}//AuraUI
