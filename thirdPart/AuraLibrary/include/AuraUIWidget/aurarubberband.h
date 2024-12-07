#pragma once

#include <QWidget>
#include <QRubberBand>

#include "UIHeader.h"

//此处应该再进行分类
namespace AuraUI {
class AuraLibrary_DECL AuraRubberBand : public QRubberBand
{
    Q_OBJECT
public:
    explicit AuraRubberBand(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent* e);
private:
    QColor m_borderColor;
    QColor m_backgroundColor;
signals:

};
}//AuraUI
