#ifndef MODEL2DMOVE_H
#define MODEL2DMOVE_H

#include <QObject>
#include "../BaseClass/componentobject.h"

class Model2DMove : public ComponentObject
{
public:
    enum Direction{
        NoDirection=0,
        Up=1,
        Down=2,
        Left=4,
        UpLeft=5,
        DownLeft=6,
        Right=8,
        UpRight=9,
        DownRight=10
    };
private:
    Q_OBJECT

    Q_PROPERTY(double xSpeed READ xSpeed WRITE setXSpeed NOTIFY xSpeedChanged)
    Q_PROPERTY(double ySpeed READ ySpeed WRITE setYSpeed NOTIFY ySpeedChanged)
    Q_PROPERTY(double xResistance READ xResistance WRITE setXResistance NOTIFY xResistanceChanged)
    Q_PROPERTY(double yResistance READ yResistance WRITE setYResistance NOTIFY yResistanceChanged)

    Q_PROPERTY(bool gravityFlag READ gravityFlag WRITE setGravityFlag NOTIFY gravityFlagChanged)
    Q_PROPERTY(double gravity READ gravity WRITE setGravity NOTIFY gravityChanged)
public:
    explicit Model2DMove(QObject *parent = nullptr);
    QJsonObject getMetaData()const override;
    void initComponent(const QJsonObject & obj)override ;

    bool gravityFlag() const;
    void setGravityFlag(bool newGravityFlag);

    double gravity() const;
    void setGravity(double newGravity);

    double xSpeed() const;
    void setXSpeed(double newXSpeed);

    double ySpeed() const;
    void setYSpeed(double newYSpeed);

    double xResistance() const;
    void setXResistance(double newXResistance);

    double yResistance() const;
    void setYResistance(double newYResistance);

signals:

    void gravityFlagChanged();

    void gravityChanged();

    void xSpeedChanged();

    void ySpeedChanged();

    void xResistanceChanged();

    void yResistanceChanged();

private:

    bool m_gravityFlag;
    double m_gravity;
    double m_xSpeed;
    double m_ySpeed;
    double m_xResistance;
    double m_yResistance;
};

REGISTER_CLASS(Model2DMove,ComponentObject)
REGISTER_COPY_CLASS(Model2DMove,ComponentObject)

#endif // MODEL2DMOVE_H
