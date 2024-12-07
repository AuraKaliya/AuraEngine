#pragma once

#include <QWidget>

#include "UIHeader.h"
#include "uiwidget.h"

namespace  AuraUI {

class AuraLibrary_DECL WheelSlideWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit WheelSlideWidget(QWidget *parent = nullptr);

    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

    void setWheelDirection(UIDirection direction);

    UIWidget *getArea() const;
    QWidget* getLastWidget();

    void setArea(int width,int height);
    void addWidgetInArea(QWidget*w,int x,int y);

    void clearWidget();

    int getBorder() const;
    void setBorder(int newBorder);

    void updateArea();
    void setLayout(QLayout * layout);

protected:
    void wheelEvent(QWheelEvent* e)override;
    void resizeEvent(QResizeEvent *e)override;
    void redoMove();

private:
    //UIDirection m_wheelDirection;
    UIWidget* m_area;
    QVector<QWidget*> m_componentWidgetList;
    int m_border;
signals:

};

}//AuraUI

