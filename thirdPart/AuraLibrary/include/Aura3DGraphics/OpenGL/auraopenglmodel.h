#pragma once

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>

#include <QMatrix4x4>
#include <QObject>
#include <QQuaternion>
#include <QColor>

#include <QOpenGLTexture>

#include <AuraGlobal.h>
#include "AuraOpenGLEnumValue.h"

#include <AuraTool/auraalgorithmtool.h>
using BoundingBoxOBB = AuraTool::BoundingBoxOBB;
using BoundingBoxAABB = AuraTool::BoundingBoxAABB;

namespace AuraUI {

struct PNVector{
    unsigned int PosIndex;
    unsigned int NormalIndex;
};

class AURAUI_LIB_DECL AuraOpenGLModel : public QObject,public QOpenGLFunctions_3_3_Core
{

    Q_OBJECT
    Q_PROPERTY(ModelDrawStratagy normalDrawStratagy READ normalDrawStratagy WRITE setNormalDrawStratagy NOTIFY normalDrawStratagyChanged FINAL)
    Q_PROPERTY(QColor ambientColor READ ambientColor WRITE setAmbientColor NOTIFY ambientColorChanged FINAL)
    Q_PROPERTY(QColor diffuseColor READ diffuseColor WRITE setDiffuseColor NOTIFY diffuseColorChanged FINAL)
    Q_PROPERTY(QColor specularColor READ specularColor WRITE setSpecularColor NOTIFY specularColorChanged FINAL)
    Q_PROPERTY(float shininess READ shininess WRITE setShininess NOTIFY shininessChanged FINAL)

public:
    void initData(InitStratagy stratagy);
    void initBuffer();
    void reInitBuffer();

    void setupVertexAttributes(unsigned int vao);
public:
    explicit AuraOpenGLModel(QObject *parent = nullptr);
    void loadData(const QVector<QVector3D>& posList,const QVector<QVector3D>& normalList,const QVector<QVector2D>& uvList,const QVector<unsigned int> & indexList);
    void loadData(const QVector<QVector3D>& posList,const QVector<QVector3D>& normalList,const QVector<unsigned int> & indexList);
    void loadData(const QVector<double>& dataList,const QVector<unsigned int> & indexList);
    void addData(const QVector<QVector3D> &postList, const QVector<QVector3D>& normalList, const QVector<unsigned int>& indexList);
    virtual void paint(QOpenGLShaderProgram * shader);
    virtual void paint(QOpenGLContext* context,QSurface* surface,QOpenGLShaderProgram * shader);
    virtual void paintBoundingBox(QOpenGLShaderProgram * shader);
    void init(InitStratagy initStratagy);

    void rotate(QQuaternion x,QQuaternion y);
    void rotate(QVector3D right,float angleY,QVector3D up,float angleX);

    ModelDrawStratagy drawStratagy() const;
    void setDrawStratagy(ModelDrawStratagy newDrawStratagy);

    bool initFlag() const;

    void check();
    QVector<QVector3D> posList() const;

    InitStratagy initStratagy() const;

    QVector<double> dataList() const;

    QVector<unsigned int> indexList() const;

    QString modelName() const;
    void setModelName(const QString &newModelName);

    QVector3D position() const;
    void updatePosition(const QVector3D &newPosition,ModelPositionUpdateStratagy stratagy);

    void createBoundingBox(ModelBoundingBoxType boundingBoxType);
    QVector<QVector3D> boundingBoxPoints() const;

    bool boundingBoxFlag() const;

    QColor ambientColor() const;
    void setAmbientColor(const QColor &newAmbientColor);

    QColor diffuseColor() const;
    void setDiffuseColor(const QColor &newDiffuseColor);

    QColor specularColor() const;
    void setSpecularColor(const QColor &newSpecularColor);


    ModelDrawStratagy normalDrawStratagy() const;
    void setNormalDrawStratagy(ModelDrawStratagy newNormalDrawStratagy);

    float shininess() const;
    void setShininess(float newShininess);

    void loadTexture(const QImage& image);

    unsigned int vbo() const;
    unsigned int ebo() const;

    BoundingBoxOBB boundingBoxOBB() const;
    BoundingBoxAABB boundingBoxAABB()const;

    ModelBoundingBoxType boundingBoxType() const;

protected:

    QString m_modelName;
    QOpenGLTexture* m_texture;

    //vao 随 widget vbo ebo（具体数据）随model
    //unsigned int m_vao=-1;
    unsigned int m_vbo=-1;
    unsigned int m_ebo=-1;

    unsigned int m_vaoBB=-1;
    unsigned int m_vboBB=-1;
    unsigned int m_eboBB=-1;

    QVector3D m_position;

    QVector<QVector3D> m_posList;       //点集

    QVector<QVector3D> m_normalList;    //法向量集

    QVector<QVector2D> m_uvList;     //纹理集

    QVector<unsigned int > m_indexList;     //索引集--传给EBO
    QVector<double> m_dataList;             //传给VBO的数据集

    QVector<QVector3D> m_boundingBoxPoints;
    QVector<double> m_boundingBoxData;
    QVector<unsigned int > m_boundingBoxIndex;

    QMatrix4x4 m_model; //暂时用不上
    QQuaternion m_modelRotation;

    //控制位/状态位
    bool m_initFlag;
    bool m_normalFlag;
    bool m_positionInitFlag;
    bool m_boundingBoxFlag;

    ModelDrawStratagy m_drawStratagy;   //绘制策略
    InitStratagy m_initStratagy;        //初始化策略


signals:

    void ambientColorChanged();
    void diffuseColorChanged();
    void specularColorChanged();
    void normalDrawStratagyChanged();

    void shininessChanged();

private:
    QColor m_ambientColor;
    QColor m_diffuseColor;
    QColor m_specularColor;
    float m_shininess;
    ModelDrawStratagy m_normalDrawStratagy;     //正常状态的一般绘制策略

    //bounding box
    ModelBoundingBoxType m_boundingBoxType;
    BoundingBoxOBB m_obb;   //此处必须要引入tool的头文件，所以后续应该写成impl的形式
    BoundingBoxAABB m_aabb;
};

}//AuraUI
