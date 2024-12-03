#pragma once

#include <QObject>
#include <QVector>
#include <QMap>
#include <QString>
#include <QVector3D>
#include "../AuraGlobal.h"
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

class AURAUI_LIB_DECL AuraOpenGLUnitManager : public QObject
{
    Q_OBJECT
public:
    explicit AuraOpenGLUnitManager(QObject *parent = nullptr);

    //void initPointList(const QVector<AuraOpenGLPoint>& pointList);
    //void initPointList(const QVector<QVector3D>& posList);

    //void initUnitList(const QVector<AuraOpenGLUnit>& unitList);
    //void initUnitList(const QVector<unsigned int>& unitIdList,const QVector<QVector<unsigned int>>& pointListList,const QVector<GeometryType>& typeList);

    void initPointDictionary(const QMap<unsigned int,AuraOpenGLPoint> & pointDictionary);
    void addPoint(unsigned int id,AuraOpenGLPoint point);

    void initUnitDictionary(const QMap<unsigned int,AuraOpenGLUnit>& unitDictionary);
    void addUnit(unsigned int id,AuraOpenGLUnit unit);

    float tubeRadius() const;
    void setTubeRadius(float newTubeRadius);

    float columRadius() const;
    void setColumRadius(float newColumRadius);

    void normalized(int base);

    QMap<unsigned int, AuraOpenGLPoint> pointDictionary() const;

    QMap<unsigned int, AuraOpenGLUnit> unitDictionary() const;

    float cubeRadius() const;
    void setCubeRadius(float newCubeRadius);

protected:
    void initUnitLinkDictionary();

private:
    //各类单元基础属性（边长、管径等）
    float m_tubeRadius;
    float m_columRadius;
    float m_cubeRadius;

    //单元对应表
    QMap<unsigned int,AuraOpenGLPoint> m_pointDictionary;
    QMap<unsigned int,AuraOpenGLUnit> m_unitDictionary;
    QMap<unsigned int,QVector<AuraOpenGLLinkUnitInfomation>> m_unitLinkDictionary;



signals:

};


}//AuraUI
