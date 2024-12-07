#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QKeyEvent>
#include <QMouseEvent>


class CardLabel : public QWidget
{
    Q_OBJECT
public:
    explicit CardLabel(QWidget *parent = nullptr);
    void setText(const QString & text);
    QString text() const;

    QPixmap & pixmap() ;

    void setPix(const QPixmap & pix);
    int topMargin() const;
    void setTopMargin(int newMargin);

    int space() const;
    void setSpace(int newSpace);

    void updateLayout();

    void paint(QPainter* p,CardLabel* w);

    std::function<void (QPainter *, CardLabel *)> paintFunction() const;
    void setPaintFunction(const std::function<void (QPainter *, CardLabel *)> &newPaintFunction);

    bool selectedFlag() const;

    qreal radius() const;
    void setRadius(qreal newRadius);

    void dragCard();

protected:
    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent* e)override;
    void mouseReleaseEvent(QMouseEvent* e)override;
    void resizeEvent(QResizeEvent*e)override;
    void paintEvent(QPaintEvent* e)override;
    void mouseDoubleClickEvent(QMouseEvent *e)override;
private:

    QString m_text;
    QPixmap m_pix;


    QColor m_cardColor;
    QColor m_textColor;

    qreal m_radius;

    int m_topMargin;
    QRect m_pixRect;
    int m_space;
    QRect m_textRect;


    QPoint m_startPoint;
    QPoint m_endPoint;

    bool m_selectedFlag;
    bool m_leftPressFlag;


    std::function<void (QPainter*,CardLabel* )> m_paintFunction;


signals:
    void pressed();
    void doubleClicked();
};

#endif // CARDLABEL_H
