#pragma once

#include <QObject>
#include <QColor>
#include <QMap>
#include <QQuaternion>
#include "auraopenglmodel.h"
#include "AuraOpenGLEnumValue.h"

namespace AuraUI {

/*
    用于对Model进行管理，  在OpenGL Widget 中进行渲染时，模型渲染阶段会从ModelManager中取得需要渲染的
    模型组和渲染方式
    Key的命名方式: 模型生成前缀+ _ +单元ID号
*/
struct RenderInformation
{
    AuraOpenGLModel* model;
    ModelRenderStratagy renderStratagy;
};

class AuraOpenGLModelManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString modelName READ modelName WRITE setModelName NOTIFY modelNameChanged FINAL)
    Q_PROPERTY(AuraUI::ModelDrawStratagy drawStratagy READ drawStratagy WRITE setDrawStratagy NOTIFY drawStratagyChanged FINAL)
    Q_PROPERTY(QColor backgroundColorMajor READ backgroundColorMajor WRITE setBackgroundColorMajor NOTIFY backgroundColorMajorChanged FINAL)

public:
    explicit AuraOpenGLModelManager(QObject *parent = nullptr);

    void addModel(QString id,AuraOpenGLModel* model);

    void addNormalRender(QString id);
    void addSelectRender(QString id);
    void addLineRender(QString id);
    void addPointRender(QString id);

    void setNormalRender(QVector<QString> idList);
    void setSelectRender(QVector<QString> idList);
    void setLineRender(QVector<QString> idList);
    void setPointRender(QVector<QString> idList);

    void resetRender();

    QVector<RenderInformation> getRenderModelList();
    QList<AuraOpenGLModel*> getModelList();
    QList<QString> getModelIdList();

    QString modelPrefix() const;
    void setModelPrefix(const QString &newModelPrefix);

    QQuaternion modelRotation() const;
    void setModelRotation(const QQuaternion &newModelRotation);

    QString modelName() const;
    void setModelName(const QString &newModelName);

    ModelDrawStratagy drawStratagy() const;
    void setDrawStratagy(ModelDrawStratagy newDrawStratagy);

    QColor backgroundColorMajor() const;
    void setBackgroundColorMajor(const QColor &newBackgroundColorMajor);

private:
    // Line_[UnitId] Frag_[UnitId]
    QMap<QString,AuraOpenGLModel*> m_modelDictionary;
    QSet<QString> m_normalSet;
    QSet<QString> m_selectSet;
    QSet<QString> m_lineSet;
    QSet<QString> m_pointSet;

    QQuaternion m_modelRotation;

private:
    QString m_modelPrefix;
    QString m_modelName;

    ModelDrawStratagy m_drawStratagy;

    QColor m_backgroundColorMajor;

signals:

    void modelNameChanged();
    void drawStratagyChanged();
    void backgroundColorMajorChanged();
};


}// namespace AuraUI
