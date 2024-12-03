#pragma once

#include <QWidget>
#include <QString>
#include <QPixmap>

#include "UIHeader.h"
#include "uiwidget.h"

namespace AuraUI {

class AURAUI_LIB_DECL AuraCardLabel : public UIWidget
{
    Q_OBJECT
    friend class UIFunction;
public:
    explicit AuraCardLabel(QWidget *parent = nullptr);
    void initWidget()override;

    QPixmap pix() const;
    void setPix(const QPixmap &newPix);

    QString text() const;
    void setText(const QString &newText);

    void setPaintFunction(CardLabelPaintFunction newPaintFunction);

    unsigned int id() const;
    void setId(unsigned int newId);

    bool selectedFlag() const;
    void setSelectedFlag(bool newSelectedFlag);

    QString introduction() const;
    void setIntroduction(const QString &newIntroduction);

protected:

    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent* e)override;
    void mouseReleaseEvent(QMouseEvent* e)override;
    void mouseDoubleClickEvent(QMouseEvent *e)override;
    void paintEvent(QPaintEvent* e)override;

protected:
    unsigned int m_id;
    QString m_text;
    QPixmap m_pix;
    QString m_introduction;

    QColor m_cardColor;
    QColor m_textColor;

    //QPoint m_startPoint;
    //QPoint m_endPoint;

    qreal m_pixRadius;
    QColor m_backgroundColor;
    QColor m_borderColor;
    unsigned int m_pixMargin;
    unsigned int m_space;

    CardLabelPaintFunction m_paintFunction;

    bool m_selectedFlag;
    bool m_leftPressFlag;

signals:
    void clicked();
    void doubleClicked();
};

} // namespace AuraUI

