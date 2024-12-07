#pragma once

#include <QObject>
#include <QVector>
#include <QMap>
#include <QString>
#include <QVector3D>

#include <AuraGlobal.h>
#include "AuraOpenGLEnumValue.h"

namespace AuraUI {


struct AuraOpenGLPoint{
    unsigned int PointId;
    QVector3D Pos;
};

struct AuraOpenGLUnit{
    unsigned int UnitId;
    QVector<unsigned int> PointList;
    GeometryType UnitType;
};

struct AuraOpenGLLinkUnitInfomation{
    unsigned int LinkUnitId;
    QVector<unsigned int> LinkPointList;
};
//unitManager 应该再添加一个：工程层 project对应一组unit，然后各w通过project获取需要的unit组
class AURAUI_LIB_DECL AuraOpenGLUnitManager : public QObject
{
    Q_OBJECT
public:
    explicit AuraOpenGLUnitManager(const QString projectName = "Project",QObject *parent = nullptr);

    void initPointDictionary(const QMap<unsigned int,AuraOpenGLPoint> & pointDictionary);
    void addPoint(unsigned int id,AuraOpenGLPoint point);

    void initUnitDictionary(const QMap<unsigned int,AuraOpenGLUnit>& unitDictionary);
    void addUnit(unsigned int id,AuraOpenGLUnit unit);

    float tubeRadius() const;
    void setTubeRadius(float newTubeRadius);

    float columRadius() const;
    void setColumRadius(float newColumRadius);

    //==========待完善=============
    void normalized(int base);
    //需要添加normalizedPointDictionary
    //需要添加normalized flag 和 在返回/使用point时 根据flag状态选择对应的PointDictionary
    //==========待完善=============

    QMap<unsigned int, AuraOpenGLPoint> pointDictionary() const;
    QMap<unsigned int, AuraOpenGLUnit> unitDictionary() const;

    float cubeRadius() const;
    void setCubeRadius(float newCubeRadius);
    bool unitNeedToCreateModelFlag() const;

    void setUnitNeedToCreateModelFlag(bool newUnitNeedToCreateModel);

private:

    AuraOpenGLUnitManager(const AuraOpenGLUnitManager&)=delete;
    AuraOpenGLUnitManager& operator = (const AuraOpenGLUnitManager&)=delete;

protected:
    void initUnitLinkDictionary();

private:
    QString m_projectName;

    //各类单元基础属性（边长、管径等）
    float m_tubeRadius;
    float m_columRadius;
    float m_cubeRadius;

    //单元对应表
    QMap<unsigned int,AuraOpenGLPoint> m_pointDictionary;
    QMap<unsigned int,AuraOpenGLUnit> m_unitDictionary;
    QMap<unsigned int,QVector<AuraOpenGLLinkUnitInfomation>> m_unitLinkDictionary;

    //flag
    bool m_unitNeedToCreateModelFlag{true};

signals:

};


}//AuraUI
