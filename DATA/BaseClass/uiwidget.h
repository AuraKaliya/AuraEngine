#ifndef UIWIDGET_H
#define UIWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QJsonObject>
#include <QJsonArray>

#include "uistyle.h"
#include "../AuraUIConstValue.h"


//=========================加入反射
#include "../../TOOL/Template/Registor.hpp"
//===============================

class GameObject;
class GameDemo;

class UIWidget : public QWidget
{
    Q_OBJECT
public:

public:
    explicit UIWidget(QWidget *parent = nullptr);
    virtual void initWidget();
    virtual void initWidget(const QJsonObject& obj);
    virtual void setUIStyle(const UIStyle & style);
    virtual void sourceUpdate();

    //==================控制位======================
    bool autoInitUIStyleFlag() const;
    AuraUI::UIDirection uiDirectionFlag() const;

    void setCenterWidget(QWidget* w);
    QWidget *centerWidget() const;

    bool checkFlag() const;
    void setCheckFlag(bool newCheckFlag);

protected:
    void setAutoInitUIStyleFlag(bool newAutoInitUIStyleFlag);
    void setUiDirectionFlag(AuraUI::UIDirection newUiDirectionFlag);
    void paintEvent(QPaintEvent*e)override;
    void resizeEvent(QResizeEvent* e) override;

private:
    //专门用于管理UIStyle的容器
    QVector<UIWidget*> m_widgetList;
    //自动设置UIStyle的控制位
    bool m_autoInitUIStyleFlag;
    //  横向UI/纵向UI；
    AuraUI::UIDirection m_uiDirectionFlag;
    // 控制检查的Flag
    bool m_checkFlag;


    QWidget * m_centerWidget=nullptr;
    bool m_centerFlag;


signals:
    void setUIStyleFinished();

    void actionSignal(QString);
    void errorSignal(QString);
    void logSignal(QString,AuraUI::LogType);

    void nowGameObjectChanged(GameObject*);
    void nowGameDemoChanged(GameDemo*);

};

#endif // UIWIDGET_H
