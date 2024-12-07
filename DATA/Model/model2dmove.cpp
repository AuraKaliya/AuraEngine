#include "model2dmove.h"

Model2DMove::Model2DMove(QObject *parent)
    : ComponentObject{parent},m_gravityFlag(false),m_gravity(0),m_xSpeed(0),m_ySpeed(0),
    m_xResistance(0),m_yResistance(0)
{
    REGISTER_TYPEID
    setObjectName("Model2DMove");
}

QJsonObject Model2DMove::getMetaData() const
{
 return QJsonObject();
}

void Model2DMove::initComponent(const QJsonObject &obj)
{
    ComponentObject::initComponent(obj);

    //get Value
    auto xResistance = obj.value("XResistance").toInteger();
    auto yResistance = obj.value("YResistance").toInteger();
    auto gravityFlag = obj.value("YResistance").toBool();
    auto gravity     = obj.value("Gravity").toInteger();

    //set Value
    setXResistance(xResistance);
    setYResistance(yResistance);
    setGravityFlag(gravityFlag);
    setGravity(gravity);

    //other
    setInitFlag(true);
}

bool Model2DMove::gravityFlag() const
{
    return m_gravityFlag;
}

void Model2DMove::setGravityFlag(bool newGravityFlag)
{
    if (m_gravityFlag == newGravityFlag)
        return;
    m_gravityFlag = newGravityFlag;
    emit gravityFlagChanged();
}

double Model2DMove::gravity() const
{
    return m_gravity;
}

void Model2DMove::setGravity(double newGravity)
{
    if (qFuzzyCompare(m_gravity, newGravity))
        return;
    m_gravity = newGravity;
    emit gravityChanged();
}

double Model2DMove::xSpeed() const
{
    return m_xSpeed;
}

void Model2DMove::setXSpeed(double newXSpeed)
{
    if (qFuzzyCompare(m_xSpeed, newXSpeed))
        return;
    m_xSpeed = newXSpeed;
    emit xSpeedChanged();
}

double Model2DMove::ySpeed() const
{
    return m_ySpeed;
}

void Model2DMove::setYSpeed(double newYSpeed)
{
    if (qFuzzyCompare(m_ySpeed, newYSpeed))
        return;
    m_ySpeed = newYSpeed;
    emit ySpeedChanged();
}

double Model2DMove::xResistance() const
{
    return m_xResistance;
}

void Model2DMove::setXResistance(double newXResistance)
{
    if (qFuzzyCompare(m_xResistance, newXResistance))
        return;
    m_xResistance = newXResistance;
    emit xResistanceChanged();
}

double Model2DMove::yResistance() const
{
    return m_yResistance;
}

void Model2DMove::setYResistance(double newYResistance)
{
    if (qFuzzyCompare(m_yResistance, newYResistance))
        return;
    m_yResistance = newYResistance;
    emit yResistanceChanged();
}
