#pragma once

#include <QObject>
#include <QRect>
#include <QVector>
#include <QVector2D>

#include "../AuraGlobal.h"

namespace AuraTool {


class AuraLibrary_DECL Fish
{

public:
    Fish();

    void doForaging(const QVector<Fish*>& fishList);
    void doGathering(const QVector<Fish*>& fishList);
    void doExcluding(const QVector<Fish*>& fishList);
    void updatePos();

    QVector2D getPosition() const;
    void setPosition(const QVector2D& pos);

private:
    QVector2D m_nowPos;
    QVector2D m_nextPos;


    float m_visual;
    double m_comfortLevel;
};


class AuraLibrary_DECL FishSwarm:public QObject
{
    Q_OBJECT
public:
    explicit FishSwarm(QObject *parent = nullptr);
    void init(unsigned int size,QRectF posRange,float step,float visual);
    void updateFishStatus();
private:
    QVector<Fish*> m_fishList;
    QRectF m_posRange;
    float m_step;
    float m_visual;
    double m_evaluationFactor;
};


class AuraLibrary_DECL FishSwarmAlgorithmTool : public QObject
{
    Q_OBJECT
public:
    explicit FishSwarmAlgorithmTool(QObject *parent = nullptr);

    void initFishSwarm(int size);
    void setMaxTurn(unsigned int maxTurn);
    void runAlgorithm();
private:
    FishSwarm m_fishSwarm;

    unsigned int m_maxTurn;

    double m_evaluationFactor;

signals:
    void updateVisualization();

};
}//AuraAlgorithm

