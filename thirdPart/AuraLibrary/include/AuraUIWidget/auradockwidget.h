#pragma once

#include <QWidget>
#include <QDockWidget>
#include <QPainter>
#include <QColor>
#include <QLabel>

#include "UIHeader.h"

#include "auratitlebar.h"

namespace AuraUI {

class AURAUI_LIB_DECL AuraDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit AuraDockWidget(const QString &title="",const QColor& bkColor=Qt::transparent,QWidget *parent = nullptr);
    void initWidget();
    QString titleText() const;
    void setTitleText(const QString &newTitleText);

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor &newBackgroundColor);

protected:
    void paintEvent(QPaintEvent *e)override;
private:
    QString m_titleText;
    QColor m_backgroundColor;
signals:

};

}// namespace AuraUI
