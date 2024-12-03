#pragma once

#include <QColor>
#include <QString>
#include <QTimer>

#include "UIHeader.h"
#include "uiwidget.h"

namespace AuraUI {
struct Progress{
    unsigned int nowValue;
    unsigned int maxValue;
};

class AURAUI_LIB_DECL AuraProgressBar : public UIWidget
{
    Q_OBJECT
    friend class UIFunction;
public:
    explicit AuraProgressBar(QWidget *parent = nullptr);
    void initWidget()override;

    void setMaxValue(unsigned int maxValue);
    void setNowValue(unsigned int nowValue);

    QFont textFont() const;
    void setTextFont(const QFont &newTextFont);
    void setTextSize(unsigned int size);

    void setPaintFunction(AuraProgressBarPaintFunction newPaintFunction);

    bool showTextFlag() const;
    void setShowTextFlag(bool newShowTextFlag);

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor &newBackgroundColor);

    QColor foregroundColor() const;
    void setForegroundColor(const QColor &newForegroundColor);

    QColor borderColor() const;
    void setBorderColor(const QColor &newBorderColor);

    QColor textColor() const;
    void setTextColor(const QColor &newTextColor);

    void animationStart();
    void animationEnd();

    bool animationFlag() const;
    void setAnimationFlag(bool newAnimationFlag);

    void setAnimationInterval(unsigned int value);
protected:
    void paintEvent(QPaintEvent* e)override;

    void checkValue();
protected:

    AuraProgressBarPaintFunction m_paintFunction;

    QString m_prefixText;
    QString m_suffixText;

    QFont m_textFont;


    Progress m_valueProgress;

    QColor m_backgroundColor;
    QColor m_foregroundColor;
    QColor m_borderColor;
    QColor m_textColor;

    bool m_showTextFlag;
    bool m_animationFlag;
    //bool m_animationInitFlag;
    QTimer * m_timer=nullptr;


signals:
    void animationTimeout();
};

}//AuraUI
