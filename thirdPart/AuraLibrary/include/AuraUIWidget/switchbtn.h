#pragma once

#include <QWidget>
#include <QColor>


#include "UIHeader.h"
#include "uiwidget.h"
namespace AuraUI {

class AURAUI_LIB_DECL AuraSwitchBtn : public UIWidget
{
    Q_OBJECT
    Q_PROPERTY(QPoint btnPos READ btnPos WRITE setBtnPos NOTIFY btnPosChanged FINAL)
    friend class UIFunction;
public:
    explicit AuraSwitchBtn(QWidget *parent = nullptr);
    void initWidget()override;

    void setPaintFunction(SwitchBarPaintFunction newPaintFunction);
    void setAnimationFunction(SwitchBarAnimationFunction newAnimationFunctionToOn,SwitchBarAnimationFunction newAnimationFunctionToOff);

    QPoint btnPos() const;
    void setBtnPos(QPoint newBtnPos);

    QColor onThemeColor() const;
    void setOnThemeColor(const QColor &newOnThemeColor);

    QColor offThemeColor() const;
    void setOffThemeColor(const QColor &newOffThemeColor);

    QColor btnThemeColor() const;
    void setBtnThemeColor(const QColor &newBtnThemeColor);

protected:
    void paintEvent(QPaintEvent *e)override;
    void resizeEvent(QResizeEvent* e)override;
    void mousePressEvent(QMouseEvent *e)override;
private:
    SwitchBarPaintFunction m_paintFunction;

    SwitchBarAnimationFunction m_toOnFunction;
    SwitchBarAnimationFunction m_toOffFunction;


    QColor m_onThemeColor;
    QColor m_offThemeColor;
    QColor m_btnThemeColor;

    QPoint m_btnPos;
    QPoint m_btnOnPos;
    QPoint m_btnOffPos;
    int m_btnSpace;

    bool m_animationStateFlag;
    bool m_activityFlag;
    bool m_enableFlag;

signals:
    void StateSwitched(bool state);

    void btnPosChanged();

public slots:
    void stateSwitch(bool state);
    void updateBtnPos();
};

}//AuraUI
