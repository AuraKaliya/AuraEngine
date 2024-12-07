#include "cardlabel.h"

#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QPainterPath>
#include <QPen>

#include "../../TOOL/QtTool/aurapixtool.h"

CardLabel::CardLabel(QWidget *parent)
    : QWidget{parent}
    ,m_text("")
    ,m_pix(QPixmap())
    ,m_cardColor(QColor(128,228,219,250))
    ,m_textColor(QColor(50,50,50,250))
    ,m_radius(15.0)
    ,m_topMargin(5)
    ,m_pixRect(QRect())
    ,m_space(5)
    ,m_textRect(QRect())
    ,m_selectedFlag(false)
    ,m_leftPressFlag(false)
{
    setPaintFunction(std::bind(&CardLabel::paint,this,std::placeholders::_1,std::placeholders::_2));
}

void CardLabel::setText(const QString &text)
{
    m_text=text;
}

QString CardLabel::text() const
{
    return m_text;
}

QPixmap &CardLabel::pixmap()
{
    return m_pix;
}

void CardLabel::setPix(const QPixmap &pix)
{
    m_pix=pix;
}

void CardLabel::mousePressEvent(QMouseEvent *e)
{
    if(e->button() ==  Qt::LeftButton)
    {
        m_leftPressFlag =true;
    }
    m_startPoint=e->pos();
    m_endPoint=e->pos();



    QWidget::mousePressEvent(e);
}

void CardLabel::mouseMoveEvent(QMouseEvent *e)
{
    m_endPoint=e->pos();

    if(m_selectedFlag && m_leftPressFlag)
    {
        dragCard();
    }



    QWidget::mouseMoveEvent(e);
}

void CardLabel::mouseReleaseEvent(QMouseEvent *e)
{
    emit pressed();

    if(e->button() ==  Qt::LeftButton)
    {
        if(m_leftPressFlag)
        {
            m_selectedFlag=!m_selectedFlag;
            update();
        }

        m_leftPressFlag =false;
    }

    QWidget::mouseReleaseEvent(e);
}

void CardLabel::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
    updateLayout();
}

void CardLabel::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter painter(this);
    m_paintFunction(&painter,this);
}

void CardLabel::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        emit doubleClicked();
    }
}

qreal CardLabel::radius() const
{
    return m_radius;
}

void CardLabel::setRadius(qreal newRadius)
{
    m_radius = newRadius;
}

void CardLabel::dragCard()
{
    QDrag * drag =new QDrag(this);
    QMimeData * data =new QMimeData;

    data ->setText("CardLabel");

    data -> setData("GameObjectClass",m_text.toLocal8Bit());

    drag->setMimeData(data);
#ifdef QDEBUGCHECK
    qDebug()<<"CardLabel::dragCard | data:"<<data;
#endif

    drag->exec();
}

bool CardLabel::selectedFlag() const
{
    return m_selectedFlag;
}

std::function<void (QPainter *, CardLabel *)> CardLabel::paintFunction() const
{
    return m_paintFunction;
}

void CardLabel::setPaintFunction(const std::function<void (QPainter *, CardLabel *)> &newPaintFunction)
{
    m_paintFunction = newPaintFunction;
}

int CardLabel::space() const
{
    return m_space;
}

void CardLabel::setSpace(int newSpace)
{
    m_space = newSpace;
}

void CardLabel::updateLayout()
{
    int w=width();
    int h=height();
    int pixLength=qMin(w-2*m_topMargin,qMin(h-2*m_topMargin,h*4/5));
    int hSpace=(w-pixLength)/2;

    m_pixRect.setRect(hSpace,m_topMargin,pixLength,pixLength);
    m_textRect.setRect(0,m_topMargin+pixLength,width(),h-m_topMargin-pixLength);

    update();
}

void CardLabel::paint(QPainter *p, CardLabel *w)
{
    Q_UNUSED(w)

    qreal radius=m_radius;
    qreal inRadius=radius;
    QRect backgroundRect(0,0,width(),height());
    if(m_selectedFlag)
    {
        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(4);

        inRadius=(inRadius*7.0)/10.0;

        backgroundRect=QRect(2,2,width()-4,height()-4);

        p->setPen(pen);
        p->setBrush(QColor(150,150,150,220));
    }
    else
    {
        p->setPen(Qt::NoPen);
        p->setBrush(QColor(190,190,190,220));
    }

    //绘制 边框 (外背景底色填充)
    p->drawRoundedRect(rect(),radius,radius);

    p->setPen(Qt::NoPen);

    //绘制内部背景
    QLinearGradient gradient(rect().topLeft(),rect().bottomLeft());
    gradient.setColorAt(0,m_cardColor);
    gradient.setColorAt(1,QColor(190,190,190,150));
    p->setBrush(QBrush(gradient));
    p->drawRoundedRect(backgroundRect,inRadius,inRadius);


    p->setBrush(Qt::NoBrush);

    //Pix
    //p->drawPixmap(m_pixRect,m_pix.scaled(m_pixRect.size()));
    p->drawPixmap(m_pixRect,AuraPixTool::getRoundRectPixmap(m_pix,m_pixRect.size(),radius));
    //text
    QFont textFont =p->font();
    textFont.setBold(true);
    textFont.setPixelSize(10);
    p->setFont(textFont);
    p->setPen(m_textColor);
    p->drawText(m_textRect,Qt::AlignCenter,m_text);
}

int CardLabel::topMargin() const
{
    return m_topMargin;
}

void CardLabel::setTopMargin(int newMargin)
{
    m_topMargin = newMargin;
}



