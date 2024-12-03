#pragma once

#include <QOpenGLFunctions_3_3_Core>
#include <QMatrix4x4>


#include <AuraGlobal.h>
#include "AuraOpenGLEnumValue.h"

namespace AuraUI {
class AURAUI_LIB_DECL AuraOpenGLCamera:public QOpenGLFunctions_3_3_Core
{
public:
    AuraOpenGLCamera(QVector3D position = QVector3D(0.0f,0.0f,0.0f),QVector3D up = QVector3D(0.0f,1.0f,0.0f),
                     float yaw = -90.0f, float pitch =0.0f);

public:
    const QVector3D & getPosition()const;
    bool isOrtho();
    float aspectRatio()const;

    void setAspectRatio(float aspectRatio);
    void setOrtho(bool orthoFlag);

    void move(AuraOpenGLCameraDirection direction);
    void rotate(float xOffset,float yOffset,bool constrainPitch =true);
    void scale(float yOffset);
    float getFar() const;
    void setFar(float newFar);

    float getNear() const;
    void setNear(float newNear);

    QMatrix4x4 viewMatrix();
    QMatrix4x4 projectionMatrix();

    float zoom() const;

    void check();
    QVector3D right() const;

    QVector3D up() const;

    float viewWidth() const;
    void setViewWidth(float newViewWidth);

    float viewHeight() const;
    void setViewHeight(float newViewHeight);

    bool isIntersected(const QVector3D& point);
    bool isIntersected(const QVector3D& startPos,const QVector3D& direction);
    bool isIntersected(const QList<QVector3D>& modelPointList);


private:
    void updateCamera();
    void resetUpdateFlag();
private:
    //定位
    mutable QVector3D m_position;

    //方向
    mutable QVector3D m_front;
    mutable QVector3D m_up;
    mutable QVector3D m_right;
    mutable QVector3D m_worldUp;
    float m_yaw;    //偏航角
    float m_pitch;  //俯仰角

    //参数
    float m_movementSpeed;
    float m_rotationSpeed;
    float m_zoom;       //缩放
    float m_aspectRatio; //宽高比
    float m_far;
    float m_near;

    //控制位
    bool m_orthoFlag;  //正交投影
    mutable bool m_positionUpdateFlag;
    mutable bool m_projectionMatrixUpdateFlag;
    mutable bool m_viewProjectionMatrixUpdateFlag;

    float m_viewWidth;
    float m_viewHeight;

private:
    static constexpr float m_minZoom = 1.0f ;
    static constexpr float m_maxZoom = 100.0f ;
    static constexpr float m_minPitch = -89.0f;
    static constexpr float m_maxPitch = 89.0f;
};

}//AuraUI
