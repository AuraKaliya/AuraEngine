#pragma once

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QPainterPath>
#include <QPen>

#include "UIHeader.h"
#include "uiwidget.h"



namespace  AuraUI {

class AuraCardLabelNormal : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraCardLabelNormal(QWidget *parent = nullptr);

signals:

};
}//AuraUI
