#pragma once

#include <QWidget>

#include "../UIHeader.h"
#include "../uiwidget.h"

namespace AuraUI {

class AuraCardWidget;


struct CarouselCardSize{
    QSize normalCardSize;
    QSize currentCardSize;
};

enum class CardDirection{
    Left,Right
};

enum class CarouselStyle:int{
    Default,
    Classify,

};


class AuraLibrary_DECL AuraCarouselWidget : public UIWidget
{
    Q_OBJECT
    friend class UIFunction;
public:
    explicit AuraCarouselWidget(QWidget *parent = nullptr);
    ~AuraCarouselWidget();

    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

    void initWidget(CarouselStyle style);

    void addCard(AuraCardWidget* card);
    void preCard();
    void nextCard();
    QVector<AuraCardWidget*> cardGroup();

    CarouselCardSize caculateCardSize();
    QPoint caculateCardPosByIdx(CardDirection direction, unsigned int idx);
public:
    int currentIdx();
    void setCurrentIdx(int idx);

    bool animationDoingFlag();
    void setAnimationDoingFlag(bool flag);

    QSize indicatorSize();
    int indicatorSpacing();

protected:
    void resetZ();
    void resetLayout();
protected:
    bool eventFilter(QObject *watched, QEvent *e)override;
    void paintEvent(QPaintEvent* e)override;
    void resizeEvent(QResizeEvent*e)override;
    void showEvent(QShowEvent *e)override;
private:
    void idxpp();
    void idxss();
private:
    class AuraCarouselWidgetPrivate;
    friend class AuraCarouselWidgetPrivate;
    QScopedPointer<AuraCarouselWidgetPrivate> m_d;
signals:
};

} // namespace AuraUI

