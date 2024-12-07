#pragma once

#include <QWidget>

#include "../UIHeader.h"
#include "../uiwidget.h"

//Qt 前置声明
class QPropertyAnimation;

namespace AuraUI {
/*

*/


enum class CardStyle:int{
    Default,
    Classify,
    Strench,
    Button
};

enum class CardState:int{
    Normal = 0,
    Hover = 1<<1,
    Pressed =1<<2,
    Selected =1<<3,

};
// 定义类型转换运算符
inline CardState operator|(CardState lhs, CardState rhs)
{
    return static_cast<CardState>(
                static_cast<int>(lhs) | static_cast<int>(rhs)
                );
}
inline CardState& operator|=(CardState& lhs, CardState rhs)
{
    lhs = lhs | rhs;
    return lhs;
}
// 定义按位与运算符
inline CardState operator&(CardState lhs, CardState rhs)
{
    return static_cast<CardState>(
                static_cast<int>(lhs) & static_cast<int>(rhs)
                );
}
// 定义按位非运算符
inline CardState operator~(CardState rhs)
{
    return static_cast<CardState>(~static_cast<int>(rhs));
}
// 定义检查函数
inline bool hasFlag(CardState state, CardState flag)
{
    return (static_cast<int>(state) & static_cast<int>(flag)) != 0;
}

class AuraLibrary_DECL AuraCardWidget : public UIWidget
{
    Q_OBJECT
    friend class UIFunction;
public:
    explicit AuraCardWidget(QWidget *parent = nullptr);
    ~AuraCardWidget();

    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

    void initWidget(CardStyle style);

    //Property=========================================
    int shadowSize()const;
    QString title()const;
    QString info()const;
    QPixmap pix()const;
    QColor textColor();
    CardState state();
    int shadowOffsetX()const;
    int shadowOffsetY()const;
    unsigned int radius() const;
    QColor backgroundColor()const;
    QColor shadowColor() const ;
    bool useRadiusFlag();


    void setShadowSize(int value);
    void setTitle(const QString & title);
    void setInfo(const QString & info);
    void setPix(const QPixmap & pix);
    void setTextColor(QColor color);
    void setShadowOffsetX(int value);
    void setShadowOffsetY(int value);
    void setRadius(unsigned int newRadius);
    void setBackgroundColor(const QColor & color);
    void setShadowColor (const QColor & color );
    void setUseRadiusFlag(bool flag);
    //Property=========================================

    // Hover=========================================
    QRect hoverRect();
    QRect normalRect();
    bool hoverAnimationDoneFlag();
    QPropertyAnimation* hoverAnimation();
    // Hover=========================================

    //================================================
    void updateShadow();
protected:
    void setHoverAnimation(QPropertyAnimation* animation);
    void setHoverRect(const QRect & hoverRect);
    void setNormalRect(const QRect &normalRect);
    void setHoverAnimationDoneFlag(bool flag);

protected:
    void mousePressEvent(QMouseEvent* e)override;
    void mouseReleaseEvent(QMouseEvent* e)override;
#ifdef USE_QT6
    void enterEvent(QEnterEvent* e)override;
#else
    void enterEvent(QEvent* e)override;
#endif
    void leaveEvent(QEvent* e)override;
    void paintEvent(QPaintEvent *e)override;


private:
    class AuraCardWidgetPrivate;
    friend class AuraCardWidgetPrivate;
    QScopedPointer<AuraCardWidgetPrivate>m_d;

signals:
    void stateChangedSig(CardState oldState,CardState newState);
    void mouseHoveredSig();
    void mouseEnteredSig();
    void mousePressedSig();
    void mouseDoublePressedSig();
};

}//AuraUI
