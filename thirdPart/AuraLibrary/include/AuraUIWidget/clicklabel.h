#pragma once
#include <QObject>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>

/*
            base
*/

#include "UIHeader.h"

class AURAUI_LIB_DECL ClickLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickLabel(QWidget *parent = nullptr);
    explicit ClickLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    void setDrawFunction(const std::function<void (QPainter *, ClickLabel *)> & newDrawFunction);
    bool isDrawFunctionEmpty();
protected:
    void paintEvent(QPaintEvent*e)override;
    void mouseReleaseEvent(QMouseEvent* e)override;
private:
    void preInit();

private:
    std::function<void(QPainter*,ClickLabel*)> m_drawFunction;
    bool drawFunctionFlag;

signals:
    void clickedMe(ClickLabel*);
    void clicked();
};


